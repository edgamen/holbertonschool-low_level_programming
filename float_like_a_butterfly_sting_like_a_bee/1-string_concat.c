#include <stdlib.h>

int string_length(char *str);

/* returns a pointer to newly allocated space in memory
   which contains copy of string given as a param */
char *string_concat(char *s1, char *s2)
{
  /* variable declarations */
  int length1;
  int length2;
  int total_length;
  char *concat_string;
  int i, j;

  /* initialization of variables */
  length1 = string_length(s1);
  length2 = string_length(s2);
  total_length = length1 + length2;
  concat_string = malloc(sizeof(char) * total_length);

  /* if malloc fails, give an error */
  if (concat_string == NULL)
    {
      /*  printf("Not enough memory left!\n"); */
      return NULL;
    }

  /* copy contents of s1 into new string */
  for (i = 0; s1[i] != '\0'; i++)
    {
      concat_string[i] = s1[i];
    }

  for (j = 0; s2[j] != '0'; i++, j++)
    {
      concat_string[i] = s2[j];
    } 

  /* copy the null char as well */
  concat_string[i] = s2[j];
    
  return concat_string;
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

#include <stdlib.h>

/* returns a pointer to newly allocated space in memory
   which contains copy of string given as a param */
char *string_concat(char *s1, char *s2)
{
  /* variable declarations */
  char *concat_string;
  int i, j;

  /* initialization of variables */
  concat_string = malloc(sizeof(s1) + sizeof(s2));

  /* if malloc fails, give an error */
  if (concat_string == NULL)
    {
      /*  printf("Not enough memory left!\n"); */
      return NULL;
    }

  /* copy contents of s1 into new string */
  for (i = 0; s1[i] != '\0'; i++)
    {
      concat_string[i] = s1[i];
    }

  /* copy the contents of s2 into the new string */
  for (j = 0; s2[j] != '0'; i++, j++)
    {
      concat_string[i] = s2[j];
    } 

  /* copy the null char as well */
  concat_string[i] = s2[j];
    
  return concat_string;
}

/* find the length of a given string 
int string_length(char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i ++)
    {
    }

  return ++i;
} */

