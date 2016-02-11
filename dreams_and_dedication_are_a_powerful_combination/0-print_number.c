#include "my_functions.h"
#include <stdio.h>

void print_number(int n)
{
  int a = n;  /* temporarily store n in a variable called a */
  int digits; /* number digits of number n */
  int power;  /* the power of each digit */

  /* find the # digits of the number n
     (divide a until it is < 1, and update # digits in each iteration) */
  for (digits = 0; a >= 1; digits ++)
      {
	a = a / 10;
      }

    print_char(digits + '0');
    print_char('\n');

    /* find the power of the number n */
    for (power = 1; digits > 1; digits --)
      {
	power = power * 10;
      }

    printf("power=%i\n",power);
}
