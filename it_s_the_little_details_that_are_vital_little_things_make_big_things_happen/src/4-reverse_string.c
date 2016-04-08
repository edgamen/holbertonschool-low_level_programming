#include <stdio.h>
int print_char(char c);
int str_len(char *str);

/* reverses a string */
void reverse_string(char *str)
{
  int n, original_value;
  int len = str_len(str);
  int reverse_index = len;
  
  printf("length = %i\n", len);
 
  for (n = 0; n <= len / 2; n++, reverse_index--) 
    {
      original_value = str[n];
      str[n] = str[reverse_index];   
      str[reverse_index] = original_value;
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


