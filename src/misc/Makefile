#
# Prerequisites
#
include $(PRJ_MK_SHARED)

subdir-y :=
subdir-y += general
subdir-y += $(DPCFG_PLATFORM)

ifeq ($(DPCFG_PLATFORM),)
$(warning "Input platform is empty.")
endif

.PHONY: default
default: all

#
# install misc files
#
.PHONY: all
install::
	@$(call CMD_PREP_DIR,$(PRJ_DIR_PACK_BIN))
	@$(foreach d,$(subdir-y),$(call CMD_CP_NOSP_R,$(subdir-y)/*,$(PRJ_DIR_PACK_BIN)/);)

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
