CC = gcc
CFLAGS = -Werror -Wextra -Wpedantic -Wall
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
EXE = maze

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
