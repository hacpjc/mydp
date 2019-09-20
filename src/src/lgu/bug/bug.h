#ifndef SRC_LGU_BUG_BUG_H_
#define SRC_LGU_BUG_BUG_H_

#include <stdio.h>
#include <assert.h>

#include <rte_debug.h>

#define BUG_ON_ENABLE (1)

#if (BUG_ON_ENABLE)
#define BUG() do { rte_panic(" * Oops: %s:%d\n", __FUNCTION__, __LINE__); } while (0)
#define BUG_ON(_condition) do { RTE_ASSERT(!(_condition)); } while (0)
#define WARN_ON(_condition) do { if ((_condition)) { fprintf(stderr, " * WARNING: At %s:%d, %s\n", __FUNCTION__, __LINE__, #_condition); } } while (0)
#else
// Optimize-out
#define BUG() do { } while (0)
#define BUG_ON(_condition) do { int __useless__ = (_condition); } while (0)
#define WARN_ON(_condition) do { int __useless__ = (_condition); } while (0)
#endif

#endif /* SRC_LGU_BUG_BUG_H_ */
