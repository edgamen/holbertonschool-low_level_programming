void reverse_array(int *a, int n);
void print_array(int *a, int n);

int main(void)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 98, 1024, 1337};
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 98, 1024, 1337, 333};
  print_array(a, sizeof(a) / sizeof(int));
  reverse_array(a, sizeof(a) / sizeof(int));
  print_array(a, sizeof(a) / sizeof(int));

  print_array(b, sizeof(b) / sizeof(int));
  reverse_array(b, sizeof(b) / sizeof(int));
  print_array(b, sizeof(b) / sizeof(int));

  return (0);
}
