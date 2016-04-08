#include <stdio.h>

/* execute a given function on each item of an array of int */
void array_iterator(int *array, int size, void (*action_func)(int))
{
  int i;

   for (i = 0; i < size; i++)
    {
      (*action_func)(array[i]);
    }
  
}
