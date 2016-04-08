#include "../inc/my_functions.h"
#include <unistd.h>

/* Print 'P', 'N', or 'Z' depending on value of argument */
void positive_or_not(int n)
{

  /* Print 'P' if argument is postive */
  if (n > 0)
  {
    print_char('P');
  }

  /* Print 'N' if argument is negative */
  if (n < 0)
  {
    print_char('N');
  }

  /* Print 'Z' if argument equals 0 */
  if (n == 0)
  {
    print_char('Z');
  }

}

int print_char(char c)
{
  return (write(1, &c, 1));
}
