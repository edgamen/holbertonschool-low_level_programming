CC = gcc
CFLAGS = -I$(INCLUDES)
VPATH = ./src/
INCLUDES = ./inc/
SOURCES = print_char.c print_string.c 0-print_content.c
OBJ = $(SOURCES:.c=.o)
EXE = 0-print_content

all: $(EXE)

$(EXE): $(OBJ)

clean:
	rm $(OBJ)

re: clean all
