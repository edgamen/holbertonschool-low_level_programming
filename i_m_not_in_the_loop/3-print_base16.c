#include "my_functions.h"

/* Print numbers of base 16 */
void print_base16(void)
{
  /* declare variable */
  char c;

    /* initialize, check and update */
  for (c = 48; c <= 70; c++)
      {
	/* don't do anything for ASCII characters not used in hexadecimal base */
	if (c > 57 && c < 65)
	  	    continue;
	  print_char(c);
      }
}
