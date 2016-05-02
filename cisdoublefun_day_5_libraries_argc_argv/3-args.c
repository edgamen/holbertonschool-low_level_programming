#include <unistd.h>
void print_string(char *str);
int print_char(char c);

/* prints all arguments it receives */
int main(int argc, char **argv)
{
  int i;
  
  while (i < argc)
    {
      print_string(argv[i]);
      i++;
    }

  return (0);
}

/* prints a string */
void print_string(char *str)
{
  int i;
  
  i = 0;
  
  while (str[i] != '\0')
    {
      print_char(str[i]);
      i++;
    }

  print_char('\n');
}

/* prints a character */
int print_char(char c)
{
  return (write(1, &c, 1));
}
