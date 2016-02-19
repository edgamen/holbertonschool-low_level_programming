#include <stdio.h>

/* print all possible smallest combinations of two different digits in ascending order */
void print_combination_2(void)
{
  int first_digit;
  int second_digit;
  
  for (first_digit = 0; first_digit < 10; first_digit ++)
    {
      for (second_digit = first_digit + 1; second_digit < 10; second_digit ++)
	{
	  printf("%d%d", first_digit, second_digit);

	  if (first_digit < 8 || second_digit < 9)
	    {
	      printf(", ");
	    }
	}
    }
}
