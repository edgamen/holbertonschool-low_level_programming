CC = gcc
CFLAGS = -Werror -Wextra -Wpedantic -Wall
SOURCES = main.c init_instance.c
OBJECTS = $(SOURCES:.c=.o)
EXE = maze

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ `sdl2-config --libs` -lSDL2_ttf

re: clean all

clean:
	rm -f *.o
