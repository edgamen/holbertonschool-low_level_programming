#include "my_functions.h"

/* print the alphabet in reverse order (lower-case) */
void print_tebahpla(void)
{
  /* variable declarations: the starting letter */
  char letter;

  /* expressions */ 
  letter = 'z';

  /* loop through letters of alphabet, printing each */ 
  while (letter >= 'a')
    {
      print_char(letter);
      letter --;
    }
}
