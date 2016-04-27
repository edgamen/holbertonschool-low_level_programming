#include <stdlib.h>

int string_length(char *str);

/* returns a pointer to newly allocated space in memory
   which contains copy of string given as a param */
char *string_dup(char *str)
{
  /* variable declarations */
  char length;
  char *dup_string;
  int i;

  /* initialization of variables */
  length = string_length(str);
  dup_string = malloc(sizeof(char) * length);

  /* if malloc fails, give an error */
  if (dup_string == NULL)
    {
      /*  printf("Not enough memory left!\n"); */
      return NULL;
    }

  /* copy contents of original string into new string */
  for (i = 0; str[i] != '\0'; i++)
    {
      dup_string[i] = str[i];
    }

  /* copy the null char as well */
  dup_string[i] = str[i];
    
  return dup_string;
}

/* find the length of a given string */
int string_length(char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i ++)
    {
    }

  return ++i;
}
