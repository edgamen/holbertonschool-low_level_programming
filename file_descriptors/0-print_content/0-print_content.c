#include "my_functions.h"

/* A program that prints the contents of a file on the stdout */
int main(int ac, char** av)
{
  /* check if the proper amount of arguments have been provided */
  if (ac != 2)
    {
      print_string("Please provide the file path as a single argument.");
      print_string("Exiting program.");
      return (1);
    }
  print_string(av[0]);

  return (0);
}
