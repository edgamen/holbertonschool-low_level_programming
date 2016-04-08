OACC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -c
SOURCES = 0-absolute.c 1-cap_string.c 2-print_array.c 3-print_string.c 5-reverse_array.c 0-contact_strings.c 1-nconcat_strings.c 2-square_root.c 3-string_ncopy.c 5-string_to_integer.c 0-lowercase.c 1-power.c 2-string_copy.c 4-positive_or_not.c lowercase.c 0-print_number.c 1-swap_int.c 2-str_len.c 4-reverse_string.c 0-uppercase_string.c  1-uppercase.c 3-is_prime_number.c 4-strings_compare.c
OBJECTS = $(SOURCES:.c=.o)
ARCHIVE = libholbertonschool.a

all : $(ARCHIVE) re

$(ARCHIVE) : $(OBJECTS)
	ar -rc $(ARCHIVE) $(OBJECTS)
	ranlib $(ARCHIVE)

%.o : src/%.c
	$(CC) $(CFLAGS) $< -o $@

re : clean

clean :
	rm -f $(OBJECTS)
