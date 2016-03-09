#include <stdio.h> /* remove later */

void print_char(int n);
int find_length(char *str);

/* print one character out of 2 in a string */
void print_string_half(char *str)
{
  int n;
  int starting_point = find_length(str) - find_length(str) / 2;

  for (n = starting_point; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    } 
}

int find_length(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {    }
  
  return (n);
}

