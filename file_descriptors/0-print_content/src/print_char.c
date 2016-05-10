#include <unistd.h>

/* prints a single char */
int print_char(char c)
{
  return (write(1, &c, 1));
}
