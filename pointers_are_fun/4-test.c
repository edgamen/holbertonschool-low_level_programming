#include <stdio.h>

void test_string(char *str)
{
  printf("%c", *(str + 0));
  *(str + 0) = '?';
  printf("%c", *(str + 0));
}
