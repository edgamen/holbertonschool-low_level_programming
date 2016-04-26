#include "my_functions.h"

/* print the alphabet */
void print_alphabet(void)
{
  /* variable declarations: the starting letter */
  char letter;

  /* expressions */ 
  letter = 'a';

  /* loop through letters of alphabet, printing each */ 
  while (letter <= 'z')
    {
      print_char(letter);
      letter ++;
    }
}
