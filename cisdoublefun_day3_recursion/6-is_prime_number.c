#include <stdio.h>

int check_if_prime(int x, int n);

int is_prime_number(int n)
{
  /* special conditions */
  if (n == 1 || n < 0)
    {
      return 0;
    }
  return check_if_prime(n - 1, n);
}

/* a recursive function to test if n is a prime number */
int check_if_prime(int x, int n)
{
  /* if we have tested all the possibilities */
  if (x == 1)
    {
      return 1;
    }
  else if (n % x == 0)
    {
      return 0;
    }

  return check_if_prime(x - 1, n);
  
}
  
