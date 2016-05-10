#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_functions.h"
#include <errno.h>
#include <stdio.h> 

/* a program that replicates the behavior of cat */
int main(int ac, char** av)
{
  char *filepath;
  
  /* start by checking the number of arguments */
  if (ac < 2)
    {
      /* for now: later we must alter to read stdin most likely */
      print_string("Please provide a file name.\n");
      print_string(av[0]);
      print_char('\n');
    }

  /* later, we will want to loop through av to do this for each argument */

  /* let's develop a function to test if the argument that is provided is a directory */

  filepath = av[1]; /* for now we set this to the first argument*/

  if (check_if_dir(filepath) == -1)
    {
      /* some error occurred, so exit the program */
      return (1);
    }
  
  return (0);
}

/* a function to test if a file is a directory */
int check_if_dir(char *filepath)
{
  struct stat filestat;

  if (stat(filepath, &filestat) == -1)
    {
      /* perhaps if we wanted to be careful about
	 print_string generating an error, we could
	 concat "3-cat: " and filepath in one string
	 at the beginning of the program, and provide
	 that variable to perror */
      print_string("3-cat: ");
      perror(filepath);
      return (-1);
    }
  if (S_ISDIR(filestat.st_mode))
    {
      print_string("3-cat: ");
      print_string(filepath);
      print_string(": Is a directory\n");
      return (1);
    }

  return (0);
}
