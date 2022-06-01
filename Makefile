
# ------------------------------------------------
# Makefile for TFetch
#
# Author: Thamognya Kodi <contact@thamognya.com>
#
# ------------------------------------------------

# Variables

TOPDIR := ./src/
IVAR := -I. -I $(TOPDIR)/include/

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

.PHONY: update

