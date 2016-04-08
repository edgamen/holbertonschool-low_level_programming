#include <unistd.h>
#include "../inc/holbertonschool.h"
#include "../inc/my_functions.h"
#include <stdio.h>

int digits;          /* number digits of number n */
int digitRetainer;   /* a retainer for the digits since the value will be modified */
int p;           /* the power of each digit */
int output;          /* the single-digit number to print */

/* takes an integer in parameter and prints it */
void print_number(int n)
{
  if (n < 0)
    {
      n = n * -1;
      print_char('-');
    }

  digits = get_digits(n);
  digitRetainer = digits;
  p = get_power();

if (n == 0)
    {
      print_char('0');
    }
  else
    {
      print_digits(n);
    }
}

/* find and return the number of digits in the number n */
int get_digits(int n)
{

  for (digits = 0; n > 0; digits ++)
  {
    n = n / 10;
  }

  return (digits);

}

/* get the power of the number by multiplying 10 for each non-initial digit */
int get_power(void)
{

  for (p = 1; digits > 1; digits --)
  {
  p = p * 10;
  }

  return (p);
}

/* computer and print value of each digit */
void print_digits(int n)
{
  int output;

  for (; digitRetainer > 0; digitRetainer --)
    {
      output = n / (p);
      print_char(output + '0');
      n = n - (output * p);
      p = p / 10;
    }

}

int print_char(char c)
{
  return (write(1, &c, 1));
}
