#include <stdlib.h>

int stringlen(char *str);
char *strcopy(char *dest, char *src);

struct String {
  char *str;
  int length;
};

/* function that returns a pointer to a String struct */
struct String *string_to_struct(char *str)
{
  char *copy_of_string;
  int string_length;
  struct String *string_struct = malloc(sizeof(struct String));

  if (string_struct == NULL)
    {
      return NULL;
    }

  /* copy the string given as a parameter into a newly allocated space */
  string_length = stringlen(str);
  copy_of_string = malloc(sizeof(char) * string_length);
  /* if there was not enough memory to create a copy of the string: */
  if (copy_of_string == NULL)
    {
      free(string_struct);
      return NULL;
    }

  copy_of_string = strcopy(copy_of_string, str);
  /* printf("copy of string: %s, address = %p\n", copy_of_string, copy_of_string); */

  string_struct->str = copy_of_string;
  /* printf("string_struct string: %s, address = %p\n", string_struct->str, string_struct->str); */

  /* also copy the length of the string into the struct */
  string_struct->length = --string_length;
  
  return string_struct;
}

/* find the length of a given string */
int stringlen(char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i ++)
    {
    }

  return ++i;
} 

/* copy a source string into a destination string */
char *strcopy(char *dest, char *src)
{
  int i;

  for (i = 0; src[i] != '\0'; i++)
    {
      dest[i] = src[i];
    }

  dest[i] = '\0';

  return dest;
}
