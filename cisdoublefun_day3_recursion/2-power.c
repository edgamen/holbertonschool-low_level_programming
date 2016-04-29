#include <limits.h>

/* return the value of x raised to the power of y */
int power(int x, int y)
{
  int result;

  result = 1;
  
  if (y < 0 || x < 1)
    {
      return (-1);
    }
  else if (y == 0)
    {
      return (1);
    }

  while (y > 0)
    {
      /* detect if operation would cause int overflow */
      if (result > INT_MAX / x)
	{
	  return (-1);
	}
      result = result * x;
      y--;
    }

  return result;
 
}
