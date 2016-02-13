#include "my_functions.h"

/* print all possible smallest combinations of two different digits in ascending order */
void print_combination_2(void)
{
  int first_digit = 0;
  int second_digit = 1;

  print_number(first_digit);   /* print the first combination */
  print_number(second_digit);
  
  for (; first_digit < 10; first_digit ++)
    {
      for (second_digit = 2; second_digit < 10; second_digit ++)
	{
          if (second_digit > first_digit)   /* print only if the second digit is larger than the first */
	    {
              print_char(',');
	      print_char(' ');
	      print_number(first_digit);
	      print_number(second_digit);
	    }
	}
      second_digit = 0;  /* reset counter for second_digit for iteration of next 10 set of digits */
    }
}
