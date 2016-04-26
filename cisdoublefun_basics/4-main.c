#include <limits.h>
int print_char(char c);
void positive_or_not(int n);

int main(void)
{
  positive_or_not(98);
  positive_or_not(0);
  positive_or_not(402);
  positive_or_not(-459);
  positive_or_not(INT_MAX + 1);
  print_char('\n');
  return (0);
}
