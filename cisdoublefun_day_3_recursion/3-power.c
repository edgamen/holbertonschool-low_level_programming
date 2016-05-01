#include <limits.h>

/* return the value of x raised to the power of y */
int power(int x, int y)
{
  /* stopping condition */
  if (y == 0)
    {
      return (1);
    }
  if (y < 0 || x < 1)
    {
      return (-1);
    }
  /* in case next step in recursion would cause int overflow */
  if (x > INT_MAX / power(x, y - 1))
    {
      return (-1);
    }

  return x * power(x, y - 1);
}
