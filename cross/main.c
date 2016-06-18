#include <stdio.h>
int string_to_integer(char *s);
int print_char(char c);
void make_cross(int size);
void print_spaces(int num);

int main (int argc, char **argv)
{
	int size;

	if (argc == 1 || (size = string_to_integer(argv[1])) <= 0) {
		return (0);
	} else if (size == 1) {
		print_char('x');
		print_char('\n');
	} else {
		make_cross(size);
	}

	return (0);
}

/* print a cross for a given size */
void make_cross(int size)
{
	int num_spaces;
	int row;

	row = 0;

	do {
		num_spaces = size - 2 - row * 2;
		print_spaces(row);
		print_char('\\');
		print_spaces(num_spaces);
		print_char('/');
		print_spaces(row);
		print_char('\n');
		row ++;
	} while (num_spaces > size % 2);
	if (size % 2 != 0) {
		print_spaces(row);
		print_char('x');
		print_spaces(row);
		print_char('\n');
		row ++;
	} while (row < size) {
		print_spaces((size - 2 - num_spaces)/2);
		print_char('/');
		print_spaces(num_spaces);
		print_char('\\');
		print_spaces((size - 2 - num_spaces)/2);
		print_char('\n');
		num_spaces = num_spaces + 2;
		row ++;
	}

}

/* print spaces for a given number */
void print_spaces(int num)
{
	while (num > 0) {
		print_char(' ');
		num --;
	}
}
B
