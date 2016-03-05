#include <stdio.h>
int print_char(char c);
int str_len(char *str);

/* reverses a string */
void reverse_string(char *str)
{
  int n;
  int len = str_len(str);
  int original_value;
  
  printf("length = %i\n", len);
 
  for (n = 0; n <= len / 2; n++, len--) 
    {
      original_value = str[n];
      str[n] = str[len];
      str[len] = original_value;
    } 
}

/* returns the length of a string array*/
int str_len(char *str)
{
  int n;

  for (n = 0; str[n + 1] != '\0'; n++)
    {
    }

  return (n);
}


