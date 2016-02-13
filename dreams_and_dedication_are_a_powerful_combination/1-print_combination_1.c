#include "my_functions.h"

/* prints all possible combinations of single-digit numbers in ascending order */
void print_combination_1(void)
{
  int i = 0;

  print_number(i);
  
  for (i = 1; i < 10; i ++)
    {     
      print_char(',');
      print_char(' ');
      print_number(i);
    }

}
