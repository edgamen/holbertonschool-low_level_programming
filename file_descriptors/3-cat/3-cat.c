#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "my_functions.h"
#define BUFFSIZE 100

/* a program that replicates the behavior of cat */
int main(int ac, char** av)
{
  char *filepath;
  int is_dir;
  
  /* start by checking the number of arguments */
  if (ac < 2)
    {
      /* for now: later we must alter to read stdin most likely */
      print_string("Please provide a file name.\n");
      print_string(av[0]);
      print_char('\n');
    }

  /* later, we will want to loop through av to do this for each argument */

  filepath = av[1]; /* for now we set this to the first argument*/

  if ( (is_dir = check_if_dir(filepath)) == -1 )
    {
      /* some error occurred, so exit the program */
      return (1);
    }
  if (!is_dir)
    {
      /* read the file and write it out on the stdout */
      if (print_file(filepath) == -1)
	{
	  /* some error occurred, so exit the program */
	  return (1);
	}
    }
  
  return (0);
}

/* a function to test if a file is a directory. 
   If no file or dir exists with the filepath name,
   then it will also print an error. */
int check_if_dir(char *filepath)
{
  struct stat filestat;

  if (stat(filepath, &filestat) == -1)
    {
      /* perhaps if we wanted to be careful about
       * print_string generating an error, we could
       * concat "3-cat: " and filepath in one string
       * at the beginning of the program, and provide
       * that variable to perror
      */
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
