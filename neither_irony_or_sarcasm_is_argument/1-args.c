#include <stdio.h>

/* prints the arguments passed to it */
int main(int ac, char **av)
{
  int i;
  for (i = 0; i < ac; i++)
    {
      printf("%s\n", av[i]);
    }

  return (0);
}
