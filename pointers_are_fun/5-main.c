#include <stdio.h>
int string_to_integer(char *s);

int main(void)
{
  int n;

  n = string_to_integer("98");
  /* printf("%d\n", n); */
  n = string_to_integer("-402");
  n = string_to_integer("        ++++++-----+++++--98");
  n = string_to_integer("2147483647");
  n = string_to_integer("0");
  n = string_to_integer("-2147483648");
  n = string_to_integer("2147483648");
  n = string_to_integer("34234232147483648");
  n = string_to_integer("Suite 402");
  n = string_to_integer("      +    +   -   -98 Battery Street; San Francisco, CA 94111 - USA         ");
  n = string_to_integer("---++++ - Sui - te -  402 #cisfun :)");

  return (n);
}
