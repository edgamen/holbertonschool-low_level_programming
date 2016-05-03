#include <limits.h>

/* return the absolute value of an integer */

int absolute(int n) {
  if (n < 0)
    {
      /* edge case */
      if (n == INT_MIN)
	{
	  return INT_MAX;
	}
      
      return (n * -1);
    }
  else {
    return (n);
  }
}
