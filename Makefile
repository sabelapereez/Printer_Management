CC = gcc -Wall
HEADER_FILES_DIR = .
INCLUDES = -I $(HEADER_FILES_DIR)
OUTPUT = executable 
LIB_HEADERS = $(HEADER_FILES_DIR)/queue.h $(HEADER_FILES_DIR)/list.h $(HEADER_FILES_DIR)/printers.h $(HEADER_FILES_DIR)/elementtype.h
SRCS = main.c queue.c list.c printers.c
OBJS = $(SRCS:.c=.o)

$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS)

%.o: %.c $(LIB_HEADERS)
	$(CC) -c -o $@ $< $(INCLUDES)

cleanall: clean
	rm -f $(OUTPUT)

clean:
	rm -f *.o *~
