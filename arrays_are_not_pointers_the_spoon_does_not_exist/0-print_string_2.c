void print_char(int n);

/* print one character out of 2 in a string */
void print_string_2(char *str)
{
  int n;
  
  for (n = 0; str[n] != '\0'; n++)
    {
      if (n % 2 == 0)
	{
	  print_char(str[n]);
	}
    }
}

