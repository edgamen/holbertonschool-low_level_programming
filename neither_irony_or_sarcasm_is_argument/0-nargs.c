#include <stdio.h>

/* prints the number of arguments passed to it */
int main(int ac, char **av)
{
  av[0] = av[0];
  printf("%i\n", ac - 1);

  return (0);
}
