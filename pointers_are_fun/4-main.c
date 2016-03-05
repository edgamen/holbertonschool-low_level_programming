#include <stdio.h>
void reverse_string(char *str);
void test_string(char *str);

int main(void)
{
  char s[10] = "Holberton";
  char st2[9] = "12345678";
  
  reverse_string(s); 
  printf("%s\n", s);

  reverse_string(st2); 
  printf("%s\n", st2);
 
  return (0);
}
