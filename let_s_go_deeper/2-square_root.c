int test_for_square_roots(int x, int n);

/* return the square root of a number */
int square_root(int n)
{
  if (n < 0)
    {
      return (-1);
    }
  else
    {
      return test_for_square_roots(1, n);
    }
    
}

/* tests numbers from 1 to n / 2 to see if they are square root of n */
int test_for_square_roots(int x, int n)
{
  if (x * x == n)
    {
      return (x);
    }
  else if (x == n / 2)
    {
      return (-1);
    }
  else
    {
      return test_for_square_roots(x + 1, n);
    }
}
