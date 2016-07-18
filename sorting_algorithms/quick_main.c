#include <stdio.h>
void quick_sort(int *, int);
/* void print_array(int *, int); */

int main(void)
{
  int i;

  int array[] = {402, 94111, 98, 12, 1024};

  /*  print_array(array, 5); */
  quick_sort(array, 5);
  /* print_array(array, 5); */

  printf("final array: ");
  for (i = 0; i < 5; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  
  return (0);
}
