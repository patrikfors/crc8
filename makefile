MAKE=make

SUBDIRS=c cpp
TARGETS=all clean

.PHONY: $(TARGETS)

$(TARGETS):
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done

