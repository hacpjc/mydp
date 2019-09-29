#
# Prerequisites
#
include $(PRJ_MK_SHARED)

subdir := $(DPCFG_PLATFORM)

.PHONY: default
default: all

#
# install misc files
#
.PHONY: all
all::
	@$(call CMD_PREP_DIR,$(PRJ_DIR_PACK_BIN))
	@$(foreach d,$(subdir),$(call CMD_CP_NOSP_R,$(subdir)/*,$(PRJ_DIR_PACK_BIN)/);)

.PHONY: all
all::
	@$(call CMD_PREP_DIR,$(PRJ_DIR_PACK_BIN))
	@$(call CMD_CP_NOSP_R,general/*,$(PRJ_DIR_PACK_BIN)/)

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
