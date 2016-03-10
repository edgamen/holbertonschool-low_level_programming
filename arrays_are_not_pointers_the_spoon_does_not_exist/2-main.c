void print_array(int *a, int n);

int main(void)
{
  int array[5];
  int array1[1];
  
  array[0] = 98;
  array[1] = 402;
  array[2] = 198;
  array[3] = 298;
  array[4] = 1024;
  print_array(array, 5);
  print_array(array1, 1);
  return (0);
}
