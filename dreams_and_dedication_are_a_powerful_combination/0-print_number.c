#include "my_functions.h"

void print_number(int n)
{
  int a = n;           /* temporarily store n in a variable called a */
  int digits;          /* number digits of number n */
  int digitRetainer;   /* a retainer for the digits since the value will be modified */
  int power;           /* the power of each digit */
  int output;          /* the single-digit number to print */

  /* find the # digits of the number n by dividing its copy by 10 until it is < 1 */
  for (digits = 0; a > 0; digits ++)
      {
	a = a / 10;
      }

  digitRetainer = digits;

    /* find the power of the number n (for every non-initial digit, multiply power by 10) */
    for (power = 1; digits > 1; digits --)
      {
	power = power * 10;
      }
    
    /* print the rest of the digits */
    for (; digitRetainer > 0; digitRetainer--)
      {
	/* divide number n by power to get the output for the digit */
	output = n / (power);

	/* print the output */
	print_char(output + '0');

	/* subtract power times the previous digit from n to obtain the remaining digits  */
	n = n - (output * power);

	power = power / 10;
      }
    
}
