#include "my_functions.h"

/* print all possible smallest combinations of two different digits in ascending order */
void print_combination_3(void)
{
  int first_digit = 0;
  int second_digit = 1;
  int third_digit = 2;

  print_number(first_digit);   /* print the first combination */
  print_number(second_digit);
  print_number(third_digit);
  
  for (; first_digit < 10; first_digit ++)
    {
      for (; second_digit < 10; second_digit ++)
	{
	  for (third_digit = 3; third_digit < 10; third_digit ++)
	    {
	      if (second_digit > first_digit && third_digit > second_digit)  
		{
		  print_char(',');
		  print_char(' ');
		  print_number(first_digit);
		  print_number(second_digit);
		  print_number(third_digit);
		}
	    }
	  third_digit = 0;
	}
      second_digit = 0; 
    }
}
