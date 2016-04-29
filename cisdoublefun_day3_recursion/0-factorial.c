#include <limits.h>

/* return factorial of a given number */
int factorial(int n)
{
  int factorial;
  int i;

  if (n < 0)
    {
      return (-1);
    }

  factorial = 1;
  i = 1;
  while (i <= n)
    {
      /* detect if operation would cause integer overflow first */
      if (factorial > INT_MAX / i)
	{
	  return (-1);
	}
      
      factorial = factorial * (i);
      i++;
    }

  return factorial;
        
}
