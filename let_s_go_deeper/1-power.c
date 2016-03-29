int power(int x,  int y)
{
  if (y < 0 || x < 0)
    {
      return (-1);
    }
  else if (y == 0)
    {
      return (1);
    }
  else if (y == 1)
    {
      return x;
    }
  else
    {
      y--;
      return x * power(x, y);
    }
}
