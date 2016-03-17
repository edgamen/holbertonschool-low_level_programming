#include <stdio.h>

/* Copies a string, including the null-terminating byte */
int strings_compare(char *s1, const char *s2)
{
  int i;
   
  for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++)
    { }
   
  return(s1[i] - s2[i]);
}
