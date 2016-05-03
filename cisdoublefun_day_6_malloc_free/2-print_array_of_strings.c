#include <unistd.h>

void print_string(char *str);

int print_char(char c)
{
  return (write(1, &c, 1));
}

/* prints the content of an array of strings */
void print_array_of_strings(char **a)
{
  int i;

  i = 0;

  while (a[i] != NULL)
    {
      print_string(a[i]);
      print_char(' ');
      i++;
    }

  print_char('\n');
}

/* prints a string */
void print_string(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    }
}
