# targets n depencies and variables

CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
OBJECTS := main.o op_functions.o get_op_func.o

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o 2-calculator

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

re: clean all

clean:
	rm -f $(OBJECTS)
	rm -f 2-calculator
