CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Werror
SRC = main.c string_to_integer.c print_char.c
OBJ = $(SRC:.c=.o)
EXE = cross

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

$(OBJ) : $(SRC)

clean :
	rm -f $(OBJ)

re : clean all
