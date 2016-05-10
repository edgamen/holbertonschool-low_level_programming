#include "my_functions.h"

int main(int ac, char** av)
{
  /* start by checking the number of arguments */
  if (ac < 2)
    {
      /* for now: later we must alter to read stdin most likely */
      print_string("Please provide a file name.\n");
      print_string(av[0]);
      print_char('\n');
    }
  
  return (0);
}
