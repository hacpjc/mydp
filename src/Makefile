#
# Prerequisites
#
include $(PRJ_MK_SHARED)

.PHONY: default
default: all

#
# mydp main program
#
dpdk-dir := $(PRJ_DIR_IMPORT)/dpdk/dpdk-19.08

extra-cflags := 

CROSS :=

build-opts :=
build-opts += EXTRA_CFAGS="$(extra-cflags)"
build-opts += RTE_SDK=$(dpdk-dir)
# build-opts := CROSS=$(CROSS) EXTRA_CFLAGS="$(EXTRA_CFLAGS)" RTE_SDK=$(DPDK_DIR)

.PHONY: all
all::
	test -d $(dpdk-dir)
	$(MAKE) -C mydp $(build-opts)

.PHONY: clean	
clean::
	rm -rf mydp/build

.PHONY: install
install::
	@echo "...install binary files into $(PRJ_DIR_PACK_BIN)"
	@mkdir -vp $(PRJ_DIR_PACK_BIN)
	@$(call CMD_CP_NOSP,mydp/build/mydp,$(PRJ_DIR_PACK_BIN))

#
# misc
#
.PHONY: all install clean
all install clean::
	$(MAKE) -C misc $@

#
# dpipc client (reliable)
#


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
