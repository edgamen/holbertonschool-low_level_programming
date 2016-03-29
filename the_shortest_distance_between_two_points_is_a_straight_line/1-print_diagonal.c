void print_char(char c);

/* print a diagonal line on the terminal */
void print_diagonal(int n)
{
  int i;
  int j = 0;

  if (n <= 0)
    {
      print_char('\n');
    }
  
  for (; n > 0; n--, j++)
    {
      for (i = j; i > 0; i--)
	{
	  print_char(' ');
	}
      print_char('\\');
      print_char('\n');
    }
}
