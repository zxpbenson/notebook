PREFIX=/usr/local
BINDIR=${PREFIX}/bin
DESTDIR=
BLDDIR = build
#BLDFLAGS = CGO_ENABLED=0 GOOS=linux GOARCH=x64
EXT=
ifeq (${GOOS},windows)
    EXT=.exe
endif

APPS = 4-19 4-20
all: $(APPS)

$(BLDDIR)/4-19: $(wildcard code/4-19/*.go)
$(BLDDIR)/4-20: $(wildcard code/4-20/*.go)

$(BLDDIR)/%:
	@mkdir -p $(dir $@)
	${BBLDFLAGS} go build -o $@ ./$*

$(APPS): %: $(BLDDIR)/%

clean:
	rm -fr $(BLDDIR)

.PHONY: clean all
.PHONY: $(APPS)

