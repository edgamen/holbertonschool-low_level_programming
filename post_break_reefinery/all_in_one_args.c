#include <stdlib.h>
#include <stdio.h>
char *all_in_one_args(int ac, char **av);
int str_len(char *s);
void strconcat(char *dest, char *src);

int main(int ac, char **av)
{
  char *s;

  s = all_in_one_args(ac, av);
  if (s == NULL)
    {
      printf("Function failed\n");
      return (1);
    }
  printf("%s", s);
  free(s);
  return (0);
}

/* return a string that concatenates the command line arguments followed by '\n' */
char *all_in_one_args(int ac, char **av)
{
  char *string;
  int str_length;
  char *newline_string;
  int i;
  int j;

  str_length = 0;
  newline_string = "\n";
  
  for (i = 0; i < ac; i++)
    {
      str_length += str_len(av[i]) + 1;
      /* printf("string length = %d\n", str_length); */
    }

  string = malloc(sizeof(char) * str_length);

  if (string == NULL)
    {
      return NULL;
    }

  for (j = 0; j < ac; j ++)
    {
      strconcat(string, av[j]);
      strconcat(string, newline_string);
    }
  
  /* change later */
  return string;
}

/* return the length of the string */
int str_len(char *s)
{
  int i;
  
  for (i = 0; s[i] != '\0'; i++)
    {
    }

  return i;
}

/* concatenates two strings */
void strconcat(char *dest, char *src)
{
  int dest_length;
  int i;
  int j;
  
  dest_length = str_len(dest);
  j = dest_length;

  for (i = 0; src[i] != '\0'; i++, j++)
    {
      dest[j] = src[i];
    }

  dest[j] = '\0';
}
