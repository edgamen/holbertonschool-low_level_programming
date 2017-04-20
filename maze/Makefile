CC = gcc
IDIR =./inc
ODIR =./obj
SRCDIR =./src
CFLAGS = -Werror -Wextra -Wpedantic -Wall -I$(IDIR) `sdl2-config --cflags`
LFLAGS = `sdl2-config --libs` -lSDL2_ttf
DEP = $(wildcard ./inc/*.h)
SOURCES = $(wildcard ./src/*.c)
OBJECTS = $(addprefix obj/,$(notdir $(SOURCES:.c=.o)))
EXE = maze

all: $(SOURCES) $(EXE) $(DEP)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

$(ODIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

re: clean all

clean:
	rm -f $(ODIR)/*.o
