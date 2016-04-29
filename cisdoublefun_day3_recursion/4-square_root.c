#include <limits.h> 
#include <stdio.h>

/* return the natural square root of a number, if it exists
   if it does not, return -1 */
int square_root(int n)
{
  int i;

  i = 1;

  if (n == 1)
    {
      return (1);
    }
  
  while (i < n)
    {
      /* used to debug what happens when operation causes int overflow */
      /* printf("i * i = %d, INT_MAX = %d\n", i * i, INT_MAX); */

      /* if n is too great a number to find a sq. root without int overflow */
      if (i > INT_MAX / i)
	{
	  return (-1);
	}
      
      if (i * i == n)
	{
	  return i;
	}
      i ++;
    }

  return (-1);
  
}
