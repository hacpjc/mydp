/*!
 * \file dpbuf
 * \brief Abstract DPDK mbuf into local-defined dpbuf, so that we can save per-packet data.
 */
#ifndef SRC_SRC_DPBUF_DPBUF_H_
#define SRC_SRC_DPBUF_DPBUF_H_

#include <stdint.h>
#include <rte_atomic.h>

#include <urcu.h>

#include "lgu/lgu.h"

/*
 * Attach this dpbuf into mbuf private data.
 */
struct dpbuf
{
	struct dpct *dpct;

	struct cds_list_head cds_list;
	struct cds_list_head cds_list_frag; // To save ip-fragment children.

	/*
	 * Add non-dpbuf-related data here.
	 */
};

#endif /* SRC_SRC_DPBUF_DPBUF_H_ */
