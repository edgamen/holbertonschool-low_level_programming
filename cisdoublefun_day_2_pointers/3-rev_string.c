#include <stdio.h>
int str_len(char *str);

/* returns a reversed string */
char *rev_string(char *s)
{
  /* variable declarations */
  int i;
  int j;
  char temp;

  /* variable initialization */
  i = 0;
  j = str_len(s) - 1;

  /* instructions */
  while (i < str_len(s) / 2)
    {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      i++;
      j--;
    }
  
  return s;
    
}

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
