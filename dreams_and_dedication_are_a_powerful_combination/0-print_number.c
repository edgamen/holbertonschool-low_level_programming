#include "my_functions.h"

void print_number(int n)
{
  int digits;          /* number digits of number n */
  int digitRetainer;   /* a retainer for the digits since the value will be modified */
  int power;           /* the power of each digit */
  int output;          /* the single-digit number to print */

  digits = get_digits(n);
  digitRetainer = digits;

  power = get_power(digits);    

    /* print the rest of the digits */
    for (; digitRetainer > 0; digitRetainer--)
      {
	output = n / (power);
	print_char(output + '0');
	n = n - (output * power);
	power = power / 10;
      }

}

int get_digits(int n)
{
  int digits;

  /* find the # digits of the number n by dividing its copy by 10 until it is < 1 */
  for (digits = 0; n > 0; digits ++)
  {
    n = n / 10;
  } 

  return (digits);

}

int get_power(int digits)
{
  int power;

  /* find the power of the number n (for every non-initial digit, multiply power by 10) */
  for (power = 1; digits > 1; digits --)
  {
  power = power * 10;
  }

  return (power);
}
