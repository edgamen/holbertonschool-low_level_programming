#include <limits.h>

/* return factorial of a given number */
int factorial(int n)
{
  
    if (n < 0)
    {
      return (-1);
    }
    else if (n <= 1)
    {
      return (1);
    }
    /* in case the next step in factorial would cause int overflow */
    else if (n > INT_MAX / factorial(n - 1))
    {
      return (-1);
    }

  return n*factorial(n - 1);
  
}
