#include "my_functions.h"

void print_alphabet(void)
{
  /* variable declarations: the starting letter */
  char letter;

  /* expressions */ 
  letter = 'a';

  while (letter <= 'z')
    {
      print_char(letter);
      letter ++;
    }
}
