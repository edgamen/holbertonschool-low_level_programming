#include <stdlib.h>

/* returns a pointer to a newly allocated space in memory, 
   which contains a copy of the string given as a parameter */
char *string_dup(char *str)
{
  char *dupstring;
  int i;

  dupstring = malloc(sizeof(*str));

  /* if malloc fails */
  if (dupstring == NULL)
    {
      return NULL;
    }
  
  i = 0;

  while (str[i] != '\0')
    {
      dupstring[i] = str[i];
      i++;
    }

  dupstring[i] = '\0';

  return dupstring;
}
