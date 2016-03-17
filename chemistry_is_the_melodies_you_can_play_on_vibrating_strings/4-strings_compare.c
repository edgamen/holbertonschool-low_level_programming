#include <stdio.h>

/* Retunrs a negative int if s1 is less than s2, positive int if s1 is greater, and 0 if the two strings are equal. */
int strings_compare(char *s1, const char *s2)
{
  int i;
   
  for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++)
    { }
   
  return(s1[i] - s2[i]);
}
