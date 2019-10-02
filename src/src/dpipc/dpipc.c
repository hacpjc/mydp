#include <stdlib.h>

#include "initops/initops.h"

static int dpipc_initops_init(void *unused)
{
	return 0;
}

static void dpipc_initops_exit(void *unused)
{
}

DEFINE_INITOPS(dpipc_initops, INITOPS_ORDER_FIRST, dpipc_initops_init, dpipc_initops_exit, NULL);
