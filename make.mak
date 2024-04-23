# Compiler
CC=gcc

# Compiler flags
CFLAGS=-c -Wall

# Directories
SRCDIR=src
OBJDIR=obj
BINDIR=bin

# Executable name
TARGET=program

# Source files
SOURCES=$(wildcard $(SRCDIR)/*.c)
OBJECTS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Default rule
all: $(BINDIR)/$(TARGET)

# Rule to compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

# Rule to link the executable
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $^ -o $@

# Clean rule
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all clean
