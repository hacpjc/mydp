#include <rte_mbuf.h>

#include "lgu/lgu.h"
#include "initops/initops.h"

#include "dpbuf.h"


struct rte_mbuf *dpbuf_alloc_raw_mbuf(void)
{
	return NULL;
}


static int pktmbuf_initops_init(void *unused)
{
	int socket_id;

	/*
	 * Alloc pktmbuf pool for each socket.
	 */


	return 0;
}

static void pktmbuf_initops_exit(void *unused)
{

}

DEFINE_INITOPS(pktmbuf_initops, INITOPS_ORDER_FIRST, pktmbuf_initops_init, pktmbuf_initops_exit, NULL);
