#include "my_functions.h"
#include <stdio.h> /* remove later on, used for testing purposes */

void print_number(int n)
{
  int a = n;  /* temporarily store n in a variable called a */
  int digits; /* number digits of number n */
  int digitRetainer; /* a retainer for the digits since the value will be modified */
  int power;  /* the power of each digit */
  int digitNumber; /* the single-digit number to print */

  /* find the # digits of the number n
     (divide a until it is < 1, and update # digits in each iteration) */
  for (digits = 0; a >= 1; digits ++)
      {
	a = a / 10;
      }

  digitRetainer = digits;

    /* find the power of the number n
       (for every non-initial digit, multiply power by 10) */
    for (power = 1; digits > 1; digits --)
      {
	power = power * 10;
      }

    /* divide number n by power to get the first digit */
    digitNumber = n / power;
    
    /* print the first digit */
    print_char(digitNumber + '0');
    
    /* print the rest of the digits */
    for (; digitRetainer > 1; digitRetainer--)
      {
	/* subtract power times the previous digit from n to obtain the next digit  */
	n = n - (digitNumber * power);

	power = power / 10;

	digitNumber = n / (power);
	
	/* print the next digit */
	print_char(digitNumber + '0');
      }
    
}
