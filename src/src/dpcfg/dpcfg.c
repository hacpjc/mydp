
#include <urcu.h>

#include "lgu/lgu.h"
#include "initops/initops.h"

#include "dpcfg.h"

/*!
 * \brief dpcfg is a read-only configuration in json format.
 *
 * - Read-only, so there's no synchronization problem.
 * - Read-only, so you can read data to your local cache to avoid processing overhead.
 */
static struct json_object *dpcfg_json = NULL;

static struct json_object *file2obj(const char *path)
{
	struct json_object *obj;

	DBG("Read json file %s", path);
	obj = json_object_from_file(path);
	if (!obj)
	{
		ERR("%s", json_util_get_last_err());
		return NULL;
	}

	return obj;
}

int dpcfg_parse(const char *path)
{
	BUG_ON(dpcfg_json != NULL); // draycfg exists.

	dpcfg_json = file2obj(path);
	if (!dpcfg_json)
	{
		return -1;
	}

	return 0; // ok
}

static int dpcfg_initops_init(void *unused)
{
	dpcfg_json = NULL;
	return 0;
}

static void dpcfg_initops_exit(void *unused)
{
	if (dpcfg_json)
	{
		json_object_put(dpcfg_json);
		dpcfg_json = NULL;
	}
}

DEFINE_INITOPS(dpcfg_initops, INITOPS_ORDER_FIRST, dpcfg_initops_init, dpcfg_initops_exit, NULL);
