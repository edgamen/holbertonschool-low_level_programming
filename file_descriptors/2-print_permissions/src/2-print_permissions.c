#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "my_functions.h"
#define FILEPATH av[1]

/* A program that prints the permissions of a file */
int main(int ac, char** av)
{

  struct stat filestat;
  
  /* check if the proper amount of arguments have been provided */
  if (ac != 2)
    {
      print_string("Please provide the file path as a single argument.\n");
      print_string("Exiting program.\n");
      return (1);
    }

  /* create a filestat by passing stat() its pointer and the filepath */
  if (lstat(FILEPATH, &filestat) == -1)
    {
      perror("lstat");
      return (1);
    }

  if (S_ISDIR(filestat.st_mode))
    print_char('d');
  else
    print_char('-');

  
  if (filestat.st_mode & S_IRUSR)
    print_char('r');
  else
    print_char('-');
  if (filestat.st_mode & S_IWUSR)
    print_char('w');
  else
    print_char('-');
  if (filestat.st_mode & S_IXUSR)
    print_char('x');
  else
    print_char('-');

  
  if (filestat.st_mode & S_IRGRP)
    print_char('r');
  else
    print_char('-');
  if (filestat.st_mode & S_IWGRP)
    print_char('w');
  else
    print_char('-');
  if (filestat.st_mode & S_IXGRP)
    print_char('x');
  else
    print_char('-');

  if (filestat.st_mode & S_IROTH)
    print_char('r');
  else
    print_char('-');
  if (filestat.st_mode & S_IWOTH)
    print_char('w');
  else
    print_char('-');
  if (filestat.st_mode & S_IXOTH)
    print_char('x');
  else
    print_char('-');

  print_char('\n');
  
  return (0);
}
