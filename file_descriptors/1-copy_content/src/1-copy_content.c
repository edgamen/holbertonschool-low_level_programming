#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my_functions.h"
#define SRC av[1]
#define DEST av[2]
#define BUFF_SIZE 100

/* A program that copies the contents of one file into another.  */
int main(int ac, char** av)
{
  int fd_src;
  int fd_dest;
  int bytes_read; 
  int bytes_written;
  char buffer[BUFF_SIZE];
  
  /* check if the proper amount of arguments have been provided */
  if (ac != 3)
    {
      print_string("Please provide two arguments only: the source file to be copied \
and the destination path for the copy.\n");
      print_string("Exiting program.\n");
      return (1);
    }

  /* open the files first */
  fd_src = open(SRC, O_RDONLY);

  /* if there is any error, return 1 */
  if (fd_src == -1)
    {
      print_string("Error opening ");
      print_string(SRC);
      print_char('\n');
      perror("open");
      return (1);
    }

  /* if the dest file does not exist, create it, and
     give -rw-r--r-- permissions. We want to truncate 
     any existing data and append since we will be calling
     write potentially more than once. */
  fd_dest = open(DEST, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 00644);

  /* if there is any error, return 1 */
  if (fd_dest == -1)
    {
      print_string("Error opening ");
      print_string(DEST);
      print_char('\n');
      perror("open");
      close(fd_src);
      return (1);
    }

  /* read a BUFF_SIZE once and continue reading until 
     bytes_read is less than BUFF_SIZE, which will 
     indicate the entire file has been read */
   do    {
      bytes_read = read(fd_src, buffer, BUFF_SIZE);
      if (bytes_read == -1)
	{
	  perror("read");
	  close(fd_src);
	  close(fd_dest);
	  return (1);
	}
      bytes_written = write(fd_dest, buffer, bytes_read);
      if (bytes_written == -1)
	{
	   perror("write");
	  close(fd_src);
	  close(fd_dest);
	  return (1);
	}

      /* Note that in certain cases the number of bytes actually
	 written may be less than the number requested. This doesn't
	 seem to be the case here, but it's also possible to write
	 a function to ensure all bytes requested are written if
	 desired. see http://www.makelinux.net/alp/098 B.2 */

   } while (bytes_read == BUFF_SIZE);

  /* close the files */
  close(fd_src);
  close(fd_dest);

  return (0);
}
