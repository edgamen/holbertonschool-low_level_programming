int print_char(char c);

/* returns length of a string */
int str_len(char *str)
{
  /* variable declarations */
  int i;

  /* variable initialization */
  i = 0;
  
  /* instructions */
  while (str[i] != '\0')
    {
      i++;
    }

  return i;
}
