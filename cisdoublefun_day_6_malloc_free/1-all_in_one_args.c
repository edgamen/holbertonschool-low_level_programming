#include <stdio.h>
#include <stdlib.h>

int str_len(char *str);
char *string_concat(char *dest, const char *src);

/* concatenates all command line arguments */
char *all_in_one_args(int ac, char **av)
{
  char *new_string;
  char new_line[2] = {'\n', '\0'};
  int length_of_entire_string;
  int i;
  int j;

  i = 0;
  j = 0;
  length_of_entire_string = 0;
  
  while (i < ac)
    {
      length_of_entire_string += str_len(av[i]) + 1;
      /* printf("length of entire_string (%d) = str_len(av[%d]) (%d) + 1, \n", length_of_entire_string, i, str_len(av[i])); */
      i++;
    }
  /* printf("%d", length_of_entire_string); */

  new_string = malloc(length_of_entire_string * sizeof(char));

  /* in case malloc fails: */
  if (new_string == NULL)
    {
      return NULL;
    }

  while (j < ac)
    {
      string_concat(new_string, av[j]);
      string_concat(new_string, new_line);
      j++;
    }

  /* append a null char at the end */
  new_string[length_of_entire_string] = '\0';

  i = 0;

  /* debugging check for allocated length v number of chars put into string:
     
     while (new_string[i] != '\0')
    {
      printf("%c, i = %d\n", new_string[i], i);
      i++;
    }

    printf("%d\n", length_of_entire_string);
  */
  
  return new_string;
}

/* concatenates two strings */
char *string_concat(char *dest, const char *src)
{
  int i;
  int j;

  i = str_len(dest);
  j = 0;

  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }

  dest[i] = '\0';

  return dest;
}

/* returns the length of a string */
int str_len(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
    }

  return (n);
}
