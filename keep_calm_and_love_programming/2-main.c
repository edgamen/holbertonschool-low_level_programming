#include <limits.h>
void print_last_digit(int n);

int main(void)
{
  print_last_digit(98);
  print_last_digit(INT_MIN);
  print_last_digit(-402);
  return (0);
}
