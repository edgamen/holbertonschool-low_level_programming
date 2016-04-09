#include <stdio.h>

/* searches for an integer stored in an array */
int advanced_search(int *array, int size, int (*check_func)(int))
{
  int i;
  int return_value = -1;

   for (i = 0; i < size; i++)
    {
      if ((*check_func)(array[i]))
	{
	  return_value = i;
	  break;
	}
    }
    return (return_value);
}
