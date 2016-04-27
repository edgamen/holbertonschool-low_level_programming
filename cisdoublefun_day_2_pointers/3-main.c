#include <stdio.h>
#include <string.h>
char *rev_string(char *);

int main(void)
{
  char *s;

  s = strdup("Holberton");
  printf("%s\n", s);
  s = rev_string(s);
  s = strdup("123456");
  printf("%s\n", s);
  s = rev_string(s);
  printf("%s\n", s);
  s = strdup("1234567");
  printf("%s\n", s);
  s = rev_string(s);
  printf("%s\n", s);
  return (0);
}
