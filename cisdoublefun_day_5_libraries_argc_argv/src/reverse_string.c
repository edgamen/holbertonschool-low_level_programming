#include "holbertonschool.h"

int str_length(char *s);

/* reverses a string */
void reverse_string(char *s)
{
  int a, b;
  char temp;

  a = 0;
  b = str_len(s) - 1;
  
  while (a < b)
    {
      temp = s[a];
      s[a] = s[b];
      s[b] = temp;
      a ++;
      b --;
    }
}
