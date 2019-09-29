#
# Prerequisites
#
include $(PRJ_MK_SHARED)

#
# tc
#
export my-cc := $(CONFIG_TC_CC)
export my-ar := $(CONFIG_TC_AR)
export my-ranlib := $(CONFIG_TC_RANLIB)
export my-strip := $(CONFIG_TC_STRIP)
export my-objdump := $(CONFIG_TC_OBJDUMP)
export my-objcopy := $(CONFIG_TC_OBJCOPY)
export my-strip-enable := $(CONFIG_TC_RUN_STRIP)

#
# cflags, ldflags
#
my-cflags-y :=
my-cflags-y += $(CONFIG_TC_EXTRA_CFLAGS)
my-cflags-y := $(filter-out "",$(my-cflags-y))

my-ldflags-y :=
my-ldflags-y += $(CONFIG_TC_EXTRA_LDFLAGS)
my-ldflags-y := $(filter-out "",$(my-ldflags-y))

CFLAGS += $(my-cflags-y)
LDFLAGS += $(my-ldflags-y)

#
# all
# 
.PHONY: all
all: lib_build lib_install

#
# dpdk
#
dpdk-tarball := dpdk-19.08.tar.xz  
dpdk := dpdk-19.08

dpdk-target := x86_64-native-linux-gcc
dpdk-opt := T=$(dpdk-target)

.PHONY: lib_build
lib_build: $(dpdk)

$(dpdk): $(dpdk-tarball)
	tar -Jxvf $(dpdk-tarball)
	$(MAKE) -C $(dpdk) $(dpdk-opt) config
	$(MAKE) -C $(dpdk) $(dpdk-opt)

.PHONY: lib_install
lib_install:
	@echo "...nop"

.PHONY: lib_clean
lib_clean:
	rm -rf $(dpdk)
	
.PHONY: lib_distclean
lib_distclean: clean


.PHONY: clean
clean: lib_clean

.PHONY: distclean
distclean: lib_distclean

.PHONY: install
install:

.PHONY: release
release:

#;
