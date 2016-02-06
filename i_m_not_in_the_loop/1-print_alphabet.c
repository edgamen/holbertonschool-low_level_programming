#include "my_functions.h"

/* print the letters of the alphabet in lowercase */
void print_alphabet(void)
{
  /* declare variable */  
  char c;

  /* initialize, check and update to print relevant ASCII symbols */
  for(c = 97; c <= 122; c++)
   {
    print_char(c);
   }

}
