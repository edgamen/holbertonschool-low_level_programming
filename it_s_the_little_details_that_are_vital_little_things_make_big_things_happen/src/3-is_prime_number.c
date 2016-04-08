int check_prime_number(int n, int x);

/* returns 1 if prime number, 0 otherwise */
int is_prime_number(int n)
{
  if (n <=1)
    {
      return (0);
    }
  else
    {
      return check_prime_number(n, 2);
    }

}

/* check if n is divisible by any number from x to n */
int check_prime_number(int n, int x)
{
  if (x == n)
    {
      return (1);
    }
  else if (n % x == 0)
    {
      return (0);
    }
  else
    {
      return check_prime_number(n, x + 1);
    }
}
