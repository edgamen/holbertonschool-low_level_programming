#include <stdio.h>

/* copies a string */
char *string_copy(char *dest, const char *src)
{
  int i;

  i = 0;
  
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i ++;
    }

  /* append null-terminating char at the end */
  dest[i] = '\0';

  return dest;
}
