#include <pthread.h>
#include <getopt.h>

#include <rte_common.h>
#include <rte_eal.h>
#include <rte_launch.h>
#include <rte_lcore.h>
#include <rte_ethdev.h>

#include "lgu/lgu.h"
#include "initops/initops.h"
#include "dataplane.h"

/*
 * The entry point of pmd busy loop for port tx/rx.
 */
static int dataplane_loop(void *unused)
{
	unsigned int lcore_id = rte_lcore_id();
	unsigned int socket_id = rte_socket_id();

	DBG("Running loop at socket %u lcore %u pthread %u", socket_id, lcore_id, pthread_self());

	return 0;
}

int dataplane_exec(void)
{
	/* launch per-lcore loop */
	rte_eal_mp_remote_launch(dataplane_loop, NULL, CALL_MASTER);

	INFO("Terminate dataplane");
	{
		unsigned int lcore_id;

		RTE_LCORE_FOREACH_SLAVE(lcore_id)
		{
			if (rte_eal_wait_lcore(lcore_id) < 0)
			{
				return -1;
			}
		}
    }

	return 0;
}

struct cmdarg
{
	unsigned int opt_background;
	char *path_conf;
};

static struct cmdarg local_cmdarg =
	{
		.opt_background = 0,
		.path_conf = "draydp.cfg",
	};

static void print_help(const char *path)
{
	printf("%s [--help|-h]\n", path);
	printf("\n");
}

static int cmdarg_parse(int argc, char **argv)
{
	int c;
	int digit_optind = 0;

	while (1)
	{
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		static struct option long_options[] =
		{
			{ "verbose", no_argument, 0, 'v' },
			{ "quiet", no_argument, 0, 'q' },
			{ "background", no_argument, 0, 'b' },
			{ "cfg", required_argument, 0, 'c' },
			{ "help", no_argument, 0, 'h' },
			{ 0, 0, 0, 0 }
		};

		c = getopt_long(argc, argv, "vqbc:h",
			long_options, &option_index);
		if (c == -1)
			break;

		switch (c)
		{
		case 'b': // background
			local_cmdarg.opt_background = 1;
			break;
		case 'c': // cfg path
			if (optarg == NULL)
			{
				ERR("Invalid cfg path");
				return -1;
			}

			local_cmdarg.path_conf = strdup(optarg);
			if (dpcfg_parse(local_cmdarg.path_conf))
			{
				return -1;
			}
			break;

		case 'q':
			stdmsg_lv_dec();
			break;
		case 'v':
			stdmsg_lv_inc();
			break;
		case 'h':
			print_help(argv[0]);
			return -1;
		default:
			print_help(argv[0]);
			return -1;
		}
	}

	if (optind < argc)
	{
		fprintf(stderr, "non-option ARGV-elements: ");
		while (optind < argc)
			fprintf(stderr, "%s ", argv[optind++]);
		fprintf(stderr, "\n");
		print_help(argv[0]);
		return -1;
	}

	return 0;
}

static int verify_dpcfg(void)
{
	/*
	 * FIXME: Check if mandatory options are ok.
	 */

	return 0; // ok
}

static void dump_dpdk_eth_dev_info(void)
{
	unsigned int portid;

	RTE_ETH_FOREACH_DEV(portid)
	{
		struct rte_eth_dev_info dev_info;

		memset(&dev_info, 0x00, sizeof(dev_info));
		rte_eth_dev_info_get(portid, &dev_info);

		DBG("port %u:", portid);
		DBG("driver_name: %s", dev_info.driver_name);
		DBG("min_rx_bufsize: %u", dev_info.min_rx_bufsize);
		DBG("max_rx_pktlen: %u", dev_info.max_rx_pktlen);
		DBG("max_rx_queues: %u", dev_info.max_rx_queues);
		DBG("max_tx_queues: %u", dev_info.max_tx_queues);
		DBG("max_mac_addrs: %u", dev_info.max_mac_addrs);
		DBG("rx_offload_capa: 0x%08x", dev_info.rx_offload_capa);
		DBG("tx_offload_capa: 0x%08x", dev_info.tx_offload_capa);
		DBG("nb_rx_queues: %u", dev_info.nb_rx_queues);
		DBG("nb_tx_queues: %u", dev_info.nb_tx_queues);
	}
}

static int verify_dpdk_ethport(void)
{
	if (rte_eth_dev_count() == 0)
	{
		ERR("No eth dev available");
		return -1;
	}

	dump_dpdk_eth_dev_info();

	/*
	 * FIXME: Check capa of each eth device.
	 */

	return 0;
}

int dataplane_init(int argc, char **argv)
{
	stdmsg_lv_set(STDMSG_LV_DBG);

	int res = rte_eal_init(argc, argv);
	if (res < 0)
	{
		return -1;
	}
	else
	{
		// Skip all eal argv
		argc -= res;
		argv += res;
	}

	/*
	 * Parse command line options.
	 */
	if (cmdarg_parse(argc, argv))
	{
		return -1;
	}

	if (verify_dpcfg())
	{
		return -1;
	}

	DBG("Master lcore %u", rte_lcore_id());

	if (verify_dpdk_ethport())
	{
		return -1;
	}

	return 0;
}

void dataplane_exit(void)
{
	initops_exec_exit();
}
