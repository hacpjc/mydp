#
# Prerequisites
#
include $(PRJ_MK_SHARED)

.PHONY: default
default: all

#
# draydp main program
#
DPDK_DIR := ${BUILD_DIR}/dpdk-cpt

CROSS := aarch64-thunderx-linux-gnu-
EXTRA_CFLAGS := $(CFLAGS)

export RTE_SDK := $(DPDK_DIR)
export RTE_ARCH := arm64
export RTE_TARGET := build

.PHONY: all
all::
	test -d $(DPDK_DIR)
	$(MAKE) -C src CROSS=$(CROSS) EXTRA_CFLAGS="$(EXTRA_CFLAGS)" RTE_SDK=$(DPDK_DIR) RTE_TARGET=$(RTE_TARGET)

.PHONY: install
install::
	@echo "...install binary files into $(PRJ_DIR_PACK_BIN)"
	@mkdir -vp $(PRJ_DIR_PACK_BIN)
	@$(call CMD_CP_NOSP,src/build/draydp,$(PRJ_DIR_PACK_BIN))

#
# misc
#
.PHONY: all
all::
	$(MAKE) -C misc	

#
# general
#
.PHONY: all
all::

.PHONY: clean
clean::

.PHONY: distclean
distclean::

.PHONY: install
install::

.PHONY: release
relase::

#;
