#include "my_functions.h"

int digits;          /* number digits of number n */
int digitRetainer;   /* a retainer for the digits since the value will be modified */
int power;           /* the power of each digit */
int output;          /* the single-digit number to print */

/* takes an integer in parameter and print last digit it */
void print_last_digit(int n)
{
  if (n < 0 && n > -2147483648)
    {
      n = n * -1;
    }

  digits = get_digits(n);
  digitRetainer = digits;
  power = get_power();

  if (n == 0)
    {
      print_char('0');
    }
  else if (n == -2147483648)
    {
      print_char('8');
    }
  else
    {
      print_digit(n);
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

  for (power = 1; digits > 1; digits --)
    {
      power = power * 10;
    }

  return (power);
}

/* compute and print value of last digit */
void print_digit(int n)
{
  int output;

  for (; digitRetainer > 0; digitRetainer --)
    {
      output = n / (power);
      n = n - (output * power);
      power = power / 10;
    }
  print_char(output + '0');
}
