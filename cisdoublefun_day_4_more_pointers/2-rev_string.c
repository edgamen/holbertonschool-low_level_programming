#include <stdio.h>

int str_length(char *s);

/* reverses a string */
char *rev_string(char *s)
{
  int a, b;
  char temp;

  a = 0;
  b = str_length(s) - 1;
  
  while (a < b)
    {
      temp = s[a];
      s[a] = s[b];
      s[b] = temp;
      a ++;
      b --;
    }

  return s;
}

/* finds the length of a string */
int str_length(char *s)
{
  int i;

  i = 0;

  while (s[i] != '\0')
    {
      i++;
    }

  return i;
}
