#include "my_functions.h"

/* print all the numbers of base 16 */
void print_base16(void)
{
  /* variable declarations: letter to be printed */
  char c;

  /* initialization of variables */
  c = '0';

  /* loop through range of characters and print if appropriate */
  while (c <= 'F')
    {
      if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
	{
	  print_char(c);
	}
      c ++;
    }
  
}
