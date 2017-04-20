CC = gcc
CFLAGS = -Werror -Wextra -Wpedantic -Wall
SOURCES = $(wildcard ./src/*.c)
DEP = $(wildcard ./inc/*.h)
OBJECTS = $(SOURCES:.c=.o)
EXE = maze

all: $(SOURCES) $(EXE) $(DEP)

$(OBJECTS): $(DEP)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ `sdl2-config --libs` -lSDL2_ttf

re: clean all

clean:
	rm -f *.o
