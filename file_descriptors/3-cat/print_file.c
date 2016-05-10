#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my_functions.h"
#define BUFF_SIZE 100

/* A program that prints the contents of a file on the stdout */
int print_file(char *filepath)
{
  int fd;   /* a file descriptor */
  int bytes_read;  /* amount of bytes read() succeeded in reading */
  char buffer[BUFF_SIZE + 1];
  
  /* open the file first */
  fd = open(filepath, O_RDONLY);

  /* if there is any error, return 1 */
  if (fd == -1)
    {
      print_string("cat-3: ");
      perror("filepath");
      return (-1);
    }

  /* read a BUFF_SIZE once and continue reading until 
     bytes_read is less than BUFF_SIZE, which will 
     indicate the entire file has been read */
  do    {
    bytes_read = read(fd, buffer, BUFF_SIZE);
    if (bytes_read == -1)
      {
	print_string("cat-3: ");
	perror("filepath");
	close(fd);
	return (-1);
      }
    buffer[bytes_read]='\0';
    print_string(buffer);
  } while (bytes_read == BUFF_SIZE);

  /* close the file */
  close(fd);

  return (1);
}
