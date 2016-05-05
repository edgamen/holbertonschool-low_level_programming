#include <unistd.h>
#include "str_struct.h"

void print_string(char *str);
void print_number(int n);
int get_digits(int n);
int get_power(int digits);
void print_digits(int n, int ten_power, int digitRetainer);

/* prints a character */
int print_char(char c)
{
  return (write(1, &c, 1));
}

/* prints the content of a struct String */
void print_string_struct(struct String *str)
{
  print_string(str->str);
  print_char(',');
  print_char(' ');
  print_number(str->length);
  print_char('\n');
}

/* prints a string */
void print_string(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    }
}

/* takes an integer in parameter and prints it */
void print_number(int n)
{

  int digits;          /* number digits of number n */
  int digitRetainer;   /* a retainer for the digits since the value will be modified */
  int ten_power;       /* the power of each digit */

  int min = 0;

  if (n < 0)
    {
      /* take care of INT_MIN scenario */
      if (n == -2147483648)
	{
	  n = -214748364;
	  min = 1;
	}
      n = n * -1;
      print_char('-');
    }

  digits = get_digits(n);
  digitRetainer = digits;
  ten_power = get_power(digits);

  if (n == 0)
    {
      print_char('0');
    }
  else
    {
      print_digits(n, ten_power, digitRetainer);

      if (min == 1) {
	print_char(8 + '0');
      }
    }
}

/* find and return the number of digits in the number n */
int get_digits(int n)
{
  int digits;

  for (digits = 0; n > 0; digits ++)
    {
      n = n / 10;
    }

  return (digits);

}

/* get the power of the number by multiplying 10 for each non-initial digit */
int get_power(int digits)
{
  int ten_power;

  for (ten_power = 1; digits > 1; digits --)
    {
      ten_power = ten_power * 10;
    }

  return (ten_power);
}

/* compute and print value of each digit */
void print_digits(int n, int ten_power, int digitRetainer)
{
  int output;

  for (; digitRetainer > 0; digitRetainer --)
    {
      output = n / (ten_power);
      print_char(output + '0');
      n = n - (output * ten_power);
      ten_power = ten_power / 10;
    }
} 
