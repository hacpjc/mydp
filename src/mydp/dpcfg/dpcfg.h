/*!
 * \file dpcfg.h
 * \brief To save dataplane configurations from input json.
 */

#ifndef SRC_SRC_DPCFG_DPCFG_H_
#define SRC_SRC_DPCFG_DPCFG_H_

#include <json-c/json.h>

int dpcfg_parse(const char *path);

#endif /* SRC_SRC_DPCFG_DPCFG_H_ */
