/* bubble sort: compare adjacent ints in array and swap if one is greater.
   this has to be done as many times as there are elements in the array
   as each time the next greatest int will float to the end. */

void bubble_sort(int *array, int size)
{
  int i, j;
  int a, b;
  int temp;

  if (size == 0 || size == 1) {
    return;
  }

  for (i = 0; i < size; i++) {

    for (j = 0; j < (size - 1) - i; j++) {
      a = array[j];
      b = array[j + 1];
      /* printf("round %d iter %d: %d, %d --> ", i, j, a, b); */
      
      if (a > b) {
	array[j] = b;
	array[j + 1] = a;
      }
      /* printf("%d, %d\n", array[j], array[j+1]); */
      
    }

  }


}
