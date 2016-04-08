int print_char(char c);

/* prints a string */
void print_string(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    }
}

 
