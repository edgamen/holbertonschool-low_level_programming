int print_char(char c);

/* prints a string */
void print_string(char *str)
{
  /* variable declarations */
  int i;

  /* variable initialization */
  i = 0;
  
  /* instructions */
  while (str[i] != '\0')
    {
      print_char(str[i]);
      i++;
    }
}
