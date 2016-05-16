CC = gcc 
CFLAGS = -Wall -Wextra -pedantic -Werror -Iinc
VPATH = ./src
SOURCES = \
print_char.c \
string_compare.c \
main.c \
print_number.c \
string_concat.c \
print_array.c \
print_string.c \
string_to_integer.c
ARCHIVE = libshell.a
OBJECTS = $(SOURCES:.c=.o)
TARGET = simple_shell

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(VPATH)/$(ARCHIVE) -o $(TARGET)

clean:
	rm $(OBJECTS)

re: clean all
