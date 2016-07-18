#include <stdio.h>

/* Quick sort: Select a random element of the array as pt of comparison (in this case, we pick the first element). 
 * Move selectors from start and end of arrays until starting selector is greater than pivot and ending selector is less than pivot. Swap them.
 * Repeat until starting and ending selectors have the same value.
 * If the first and last selector equal each other, split the array.
 * Repeat with recursion, stopping when array is two or less element.
 */

void quick_sort(int *array, int size)
{
  int start_index;
  int end_index;
  int start_value;
  int temp;

  if (size < 2) {
    return;
  }

  /* printf("before: ");
  for (temp = 0; temp < size; temp ++) {
    printf("%d, ", array[temp]);
  }
  printf("\n"); */

  start_index = 0;
  end_index = size - 1;
  start_value = array[start_index];
  while (array[start_index] != array[end_index]) {
    while (array[start_index] < start_value) {
      start_index++;
    }
    while (array[end_index] > start_value) {
      end_index--;
    }
    if (array[start_index] == array[end_index]) {
      break;
    }
    
    temp = array[start_index];
    array[start_index] = array[end_index];
    array[end_index] = temp;
  }
  /* printf("after: ");
  for (temp = 0; temp < size; temp ++) {
    printf("%d, ", array[temp]);
  }
  printf("\n"); */

  if (size > 2) {
    quick_sort(array, start_index); /* sort array from beginnning to ending value of first partition */
    quick_sort((array + (start_index + 1)), size - (start_index + 1)); /* sort array from after partition to end */
  }
  
}
