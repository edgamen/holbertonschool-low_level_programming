#include <stdio.h>

/* Quick sort: Select a random element of the array as pt of comparison (in this case, we pick the first element). 
 * Compare first and last elements; swap if first is larger than last. Otherwise, move selector from last element to preceding. (j - 1)
 * When elements have swapped, move first selector to next element (e.g. i + 1). Compare to last selector (the former first selector).
 * If the first and last selector equal each other, split the array.
 * Repeat with recursion, stopping when array is two or less element.
 */

void quick_sort(int *array, int size)
{
  int start_index;
  int end_index;
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
  while (array[start_index] != array[end_index]) {
    if (array[start_index] > array[end_index]) {
      temp = array[start_index];
      array[start_index] = array[end_index];
      array[end_index] = temp;
      start_index++;
    } else {
      end_index--;
    }
  }
  /* printf("after: ");
  for (temp = 0; temp < size; temp ++) {
    printf("%d, ", array[temp]);
  }
  printf("\n"); */

  if (size > 2) {
    quick_sort(array, start_index + 1); /* sort array from beginnning to starting index */
    quick_sort((array + (start_index + 1)), size - (start_index + 1)); /* sort array from after partition to end */
  }
  
}
