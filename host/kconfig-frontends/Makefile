
INST_DIR := .inst

.PHONY: all clean distclean 
all:: 
	@$(MAKE) -C kconfig-frontends MY_PREFIX=DPCFG_
	@$(MAKE) -C kconfig-frontends install MY_OUTPUT=$(CURDIR)/$(INST_DIR)

distclean::
	@$(MAKE) -C kconfig-frontends distclean
	@rm -rvf $(INST_DIR)

clean::
	@$(MAKE) -C kconfig-frontends clean

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
