CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SOURCES = op_functions.c get_op_func.c main.c
OBJECTS = $(SOURCES:.c=.o)
EXE = 2-calculator

all : $(EXE)

$(EXE) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXE)
