
# ------------------------------------------------
# Makefile for TFetch
#
# Author: Thamognya Kodi <contact@thamognya.com>
#
# ------------------------------------------------

# Variables

TOPDIR := ./src/
IVAR := -I. -I $(TOPDIR)/include/
PREFIX=/usr/local
BINDIR=${PREFIX}/bin
DOCDIR=${PREFIX}/share/doc/TFetch
MANDIR=${PREFIX}/share/man
LICENSEDIR=${PREFIX}/share/licenses/TFetch

# Process

TARGET   = tfetch

CC       = gcc
CFLAGS   = -std=c99 -Wall $(IVAR)

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall $(IVAR) -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -rf


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

.PHONY: install
install:
	make
	cp ./bin/tfetch /usr/bin/

.PHONY: uninstall
install:
	rm /usr/bin/tfetch

.PHONY: doc
doc:
	mkdir -p ${DESTDIR}${MANDIR}/man1
	mkdir -p ${DESTDIR}${DOCDIR}
	mkdir -p ${DESTDIR}${LICENSEDIR}
	chmod 644 docs/man/TFetch.1 LICENSE.md
	cp docs/man/TFetch.1 ${DESTDIR}${MANDIR}/man1
	cp LICENSE.md ${DESTDIR}${LICENSEDIR}

.PHONY: update
update:
	git add .
	git commit -m "Auto Update"
	git remote | xargs -L1 git push --all
