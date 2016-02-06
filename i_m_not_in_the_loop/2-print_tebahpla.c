#include "my_functions.h"

void print_tebahpla(void)
{
  /* declare variable */  
  char c;

  /* print the alphabet in lowercase and reverse order */
  /* initialize, check and update */
  for(c = 122; c >= 97; c--)
   {
    print_char(c);
   }

}
