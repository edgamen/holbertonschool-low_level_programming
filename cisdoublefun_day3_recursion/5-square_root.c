#include <limits.h>

/* returns the natural square root of a number, using recursion */
int check_for_square_root(int x, int n);

int square_root(int n)
{
  if (n < 0)
    {
      return (-1);
    }
  if (n == 1 || n == 0)
    {
      return (n);
    }

  /* else check for square roots: */
  return check_for_square_root(n/2, n);
}

/* recursive function to check if n has a square root */
int check_for_square_root(int x, int n)
{
  if (x == 0)
    {
      return (-1);
    }
  /* in the case the number is too great for us to find sq. root without int overflow */
  if (x > INT_MAX / x)
    {
      return (-1);
    }
  else if (x * x == n)
    {
      return (x);
    }

  return check_for_square_root(x - 1, n);
    
}
