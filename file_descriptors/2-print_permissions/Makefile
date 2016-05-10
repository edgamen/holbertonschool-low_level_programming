CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I$(INCLUDES)
VPATH = ./src/
INCLUDES = ./inc/
SOURCES = print_char.c print_string.c 2-print_permissions.c
OBJ = $(SOURCES:.c=.o)
EXE = 2-print_permissions

all: $(EXE)

$(EXE): $(OBJ)

clean:
	rm $(OBJ)

re: clean all
