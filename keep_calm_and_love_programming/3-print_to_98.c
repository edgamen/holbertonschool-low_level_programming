#include <stdio.h>

/* prints all numbers from argument to 98, followed by new line */
void print_to_98(int n)
{
  printf("%d",n);

  if (n > 98)
    {
      for (n--; n >= 98; n--)
	{
	  printf(", %d", n);
	}
    }
  else if (n < 98)
    {
      for (n++; n <= 98; n++)
	{
	  printf(", %d", n);
	}
    }

  printf("\n");
}
