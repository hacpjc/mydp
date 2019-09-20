
my-src-y :=

my-src-y += lgu/fio/fio_lock.c
my-src-y += lgu/fio/fio_easyrw.c
my-src-y += lgu/hexdump/hexdump.c
my-src-y += lgu/stdmsg/stdmsg.c
my-src-y += initops/initops.c

my-src-y += dpcfg/dpcfg.c
my-src-y += dataplane.c
my-src-y += main.c

#
# local flags
#
my-cflags-y :=
my-cflags-y += -I$(PRJ_DIR_SRC)/src
my-cflags-y += $(EXTRA_CFLAGS)
my-cflags-y += -I$(PRJ_DIR_STAGE_INC)

my-ldflags-y := -lpthread
my-ldflags-y += -L$(PRJ_DIR_STAGE_LIB) -ljson-c -lurcu


#
# Standard DPDK extapp makefile. Do not edit.
#
ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif

# Default target, can be overridden by command line or environment
RTE_TARGET ?= x86_64-native-linuxapp-gcc

include $(RTE_SDK)/mk/rte.vars.mk

# binary name
APP = mydp

# all source are stored in SRCS-y
SRCS-y :=
SRCS-y += $(my-src-y)

CFLAGS += $(my-cflags-y)
LDFLAGS += $(my-ldflags-y)

# workaround for a gcc bug with noreturn attribute
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=12603
ifeq ($(DPCFG_RTE_TOOLCHAIN_GCC),y)
CFLAGS_main.o += -Wno-return-type
endif

include $(RTE_SDK)/mk/rte.extapp.mk
#;
