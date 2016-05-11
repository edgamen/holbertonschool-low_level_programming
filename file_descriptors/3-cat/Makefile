CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I$(INCLUDES)
VPATH = ./src/
INCLUDES = ./inc/
SOURCES = print_char.c print_string.c print_file.c 3-cat.c
OBJ = $(SOURCES:.c=.o)
EXE = 3-cat

all: $(EXE)

$(EXE): $(OBJ)

clean:
	rm $(OBJ)

re: clean all
