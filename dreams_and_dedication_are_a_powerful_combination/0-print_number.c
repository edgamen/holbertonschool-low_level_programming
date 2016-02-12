#include "my_functions.h"
#include <stdio.h> /* remove later on, used for testing purposes */

void print_number(int n)
{
  int a = n;  /* temporarily store n in a variable called a */
  int digits; /* number digits of number n */
  int power;  /* the power of each digit */
  int digitnumber; /* the single-digit number to print */

  /* find the # digits of the number n
     (divide a until it is < 1, and update # digits in each iteration) */
  for (digits = 0; a >= 1; digits ++)
      {
	a = a / 10;
      }

  printf("digit=%i\n",digits);

    /* find the power of the number n
       (for every non-initial digit, multiply power by 10) */
    for (power = 1; digits > 1; digits --)
      {
	power = power * 10;
      }

    printf("power=%i\n",power);

    /* obtain the first digit by dividing n by power */
    digitnumber = n / power;

    /* print the first digit */ 
    print_char(digitnumber + '0');
    print_char('\n');
      
    /* subtract power from n to obtain the second digit  */
    n = n - (digitnumber * power);
    printf("remainder=%i\n",n);
    
    power = power / 10;
    
    digitnumber = n / (power);
    
    /* print the second digit */
    print_char(digitnumber + '0');
    print_char('\n');
    
}
