#include "my_functions.h"

/* print all possible smallest combinations of two 2-digit numbers in ascending order */
void print_combination_4(void)
{
  int n1;
  int n2;
  
  for (n1 = 0; n1 < 100; n1 ++)
    {
      for (n2 = n1 + 1; n2 < 100; n2 ++)
	{
	  if (n1 < 10) {
	    print_number(0);
	  }
	  print_number(n1);
	  print_char(' ');
	  if (n2 < 10) {
	    print_number(0);
	  }
	  print_number(n2);

	  if (n1 < 98 || n2 < 99)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	}
    }
}
