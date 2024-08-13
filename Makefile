CC = gcc -Wall
TARGET = executable
SRCDIR = .
TADDIR = TADs
PRINTDIR = Printers_Library
ARGS = File_Example

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:.c=.o)

TAD_SOURCES := $(wildcard $(TADDIR)/*.c)
TAD_OBJECTS := $(TAD_SOURCES:.c=.o)

IMP_SOURCES := $(wildcard $(PRINTDIR)/*.c)
IMP_OBJECTS := $(IMP_SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS) $(TAD_OBJECTS) $(IMP_OBJECTS)
	$(CC) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

$(TADDIR)/%.o: $(TADDIR)/%.c
	$(CC) -c $< -o $@

$(IMPDIR)/%.o: $(IMPDIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TAD_OBJECTS) $(IMP_OBJECTS)

cleanall: clean
	rm -f  $(TARGET)

run: $(TARGET)
	./$(TARGET) $(ARGS)