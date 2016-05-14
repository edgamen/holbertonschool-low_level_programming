#include <stdlib.h>
#include "shell_functions.h"

/* Function: print each item of an array of strings                                            followed by a new line */
void print_array(char **array)
{
  int i;

  for (i = 0; array[i] != NULL; i++) {
    print_string(array[i]);
    print_char('\n');
  }

}
