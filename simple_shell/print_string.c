#include "shell_functions.h"

/* prints a string */
void print_string(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    }
}
