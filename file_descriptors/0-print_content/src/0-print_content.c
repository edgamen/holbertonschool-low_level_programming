#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my_functions.h"
#define FILENAME av[1]
#define BUFF_SIZE 100

/* A program that prints the contents of a file on the stdout */
int main(int ac, char** av)
{
  int fd;   /* a file descriptor */
  int bytes_read;  /* amount of bytes read() succeeded in reading */
  char buffer[BUFF_SIZE + 1];
  
  /* check if the proper amount of arguments have been provided */
  if (ac != 2)
    {
      print_string("Please provide the file path as a single argument.\n");
      print_string("Exiting program.\n");
      return (1);
    }

  /* open the file first */
  fd = open(FILENAME, O_RDONLY);

  /* if there is any error, return 1 */
  if (fd == -1)
    {
      perror("open");
      return (1);
    }

  /* read a BUFF_SIZE once and continue reading until 
     bytes_read is less than BUFF_SIZE, which will 
     indicate the entire file has been read */
   do    {
      bytes_read = read(fd, buffer, BUFF_SIZE);
      if (bytes_read == -1)
	{
	  perror("read");
	  close(fd);
	  return (1);
	}
      buffer[bytes_read]='\0';
      print_string(buffer);
   } while (bytes_read == BUFF_SIZE);

  /* close the file */
  close(fd);

  return (0);
}
