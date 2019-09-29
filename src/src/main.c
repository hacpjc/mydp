#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <urcu.h>

#include "generated/autoconf.h"
#include "lgu/lgu.h"
#include "initops/initops.h"

#include "dataplane.h"

static int process_lock_fd = -1;

static int trylock_process(void)
{
    const char *process_lock_path = DPCFG_DP_LOCK_PATH;

    process_lock_fd = fio_trylock(process_lock_path);
    if (process_lock_fd < 0)
    {
        ERR("Another instance is locking '%s'", process_lock_path);
        return -1;
    }

    return 0; // ok
}

static void unlock_process(void)
{
    if (process_lock_fd >= 0)
    {
        fio_unlock(process_lock_fd);
        process_lock_fd = -1;
    }
}

static int keep_single(void)
{
    if (trylock_process())
    {
        return -1;
    }

    atexit(unlock_process);
    return 0;
}

static void default_signal_handler(int signo)
{
	DBG("Recv signal %d", signo);
}

static int early_signal_register(void)
{
#if 1 // TODO: Remove later.
	signal(SIGHUP, default_signal_handler);
	signal(SIGPIPE, default_signal_handler);
	signal(SIGCHLD, default_signal_handler);
	signal(SIGALRM, default_signal_handler);
#endif

	return 0;
}


/*
 * Input: configuration file in json format.
 */
int main(int argc, char **argv)
{
	if (early_signal_register())
	{
		return -1;
	}

	if (keep_single())
	{
		ERR("Cannot exec multiple instance");
		return -1;
	}

    if (0)
    {
        DBG("Put into background");

        if (setsid() < 0)
        {
            ERR("Cannot setsid '%s'", strerror(errno));
            return -1;
        }

        if (daemon(0, 0))
        {
            ERR("Cannot put into background '%s'", strerror(errno));
            return -1;
        }

        stdmsg_lv_set(STDMSG_LV_NONE); // TODO: Use other logger instead.
    }

	if (dataplane_init(argc, argv))
	{
		return -1;
	}
	atexit(dataplane_exit);

	/*
	 * Init all other subsys here.
	 */
	if (initops_exec_init())
	{
		return -1;
	}
	atexit(initops_exec_exit);

	return dataplane_exec();
}
