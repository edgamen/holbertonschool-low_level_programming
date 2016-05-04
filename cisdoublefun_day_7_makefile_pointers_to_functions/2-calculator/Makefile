CC = gcc
CFLAGS = -c -I$(INCLUDES)
VPATH = src/
INCLUDES = inc/
SOURCES = absolute.c cap_string.c first_digit.c lowercase.c positive_or_not.c power.c print_array.c print_char.c print_number.c print_string.c reverse_string.c square_root.c str_len.c string_to_integer.c strings_compare.c swap_int.c uppercase.c uppercase_string.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = libholbertonschool.a

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	ar -rc $(TARGET) $(OBJECTS)
	ranlib $(TARGET)

# no need for this because of implicit rules using variables
# .c.o: (same as: %.o : %.c)
#	$(CC) $(CFLAGS) $< -o $@

clean :
	rm $(OBJECTS) $(TARGET)

re : clean all
