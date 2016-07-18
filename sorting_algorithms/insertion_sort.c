/* Maintain an incrementally sorted array: gradually add new elements, making sure each time an element is added the array is sorted */
void insertion_sort(int *array, int size)
{
  int size_sorted_list;
  int sorted_index;
  int i;
  int temp;
  
  if (size == 0 || size == 1) {
    return;
  }

  size_sorted_list = 1;

  while (size_sorted_list < size) {
    i = size_sorted_list;
    sorted_index = i - 1;
    /* if the element to be added is smaller than the preceding element in the sorted array,
       swap the two, and continue swapping until it is in the appropriate position (greater
       than the preceding element */
    while (sorted_index >= 0 && array[i] < array[sorted_index]) {
      temp = array[i];
      array[i] = array[sorted_index];
      array[sorted_index] = temp;
      i--;
      sorted_index--;
    }
    size_sorted_list++;
  }
}
