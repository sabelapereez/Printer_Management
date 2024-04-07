CC = gcc -Wall
HEADER_FILES_DIR = .
INCLUDES = -I $(HEADER_FILES_DIR)
OUTPUT = ejecutable 
LIB_HEADERS = $(HEADER_FILES_DIR)/cola.h $(HEADER_FILES_DIR)/lista.h $(HEADER_FILES_DIR)/impresoras.h $(HEADER_FILES_DIR)/tipoelemento.h
SRCS = main.c cola.c lista.c impresoras.c
OBJS = $(SRCS:.c=.o)

#regla 1 (dependencia de los .o)
$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS)

#regla 2 (genera los .o cuando es necesario, dependencia de los .c y .h)
%.o: %.c $(LIB_HEADERS)
	$(CC) -c -o $@ $< $(INCLUDES)

# regla 3 que borra el ejecutable (prerrequisito: clean)
cleanall: clean
	rm -f $(OUTPUT)

#regla 4 que borra los ficheros .o y los de backup (terminan en ~)
clean:
	rm -f *.o *~
