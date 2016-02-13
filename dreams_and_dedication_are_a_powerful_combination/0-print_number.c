#include "my_functions.h"

/* takes an integer in parameter and prints it */
void print_number(int n)
{
  int digits;          /* number digits of number n */
  int digitRetainer;   /* a retainer for the digits since the value will be modified */
  int power;           /* the power of each digit */
  int output;          /* the single-digit number to print */

  digits = get_digits(n);
  digitRetainer = digits;

  power = get_power(digits);    

  if (n == 0)
    {
      print_char('0');
    }

  else
    {      
      for (; digitRetainer > 0; digitRetainer--)    /* compute and print value of each digit */
      {
	output = n / (power);
	print_char(output + '0');
	n = n - (output * power);
	power = power / 10;
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
  int power;

  for (power = 1; digits > 1; digits --)
  {
  power = power * 10;
  }

  return (power);
}
