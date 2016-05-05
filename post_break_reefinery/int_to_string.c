#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
char *int_to_string(int);
int find_num_digits(int n);
int str_len(char *s);

int main(void)
{

  char *str;

  str = int_to_string(-98);
  printf("%s\n", str);
  free(str);
  str = int_to_string(402);
  printf("%s\n", str);
  free(str);
  str = int_to_string(-12);
  printf("%s\n", str);
  free(str);
  str = int_to_string(0);
  printf("%s\n", str);
  free(str);
  str = int_to_string(INT_MAX);
  printf("%s\n", str);
  free(str);
  str = int_to_string(INT_MIN);
  printf("%s\n", str);
  free(str);
  return (0);
}

/* returns a string representing number given as parameter */
char *int_to_string(int n)
{
  int digits;
  int str_length;
  char *s;
  int was_negative;
  int i;

  str_length = 1;
  was_negative = 0;
  
  if (n < 0)
    {
      str_length++;
      n *= -1;
      was_negative = 1;
    }
  
  digits = find_num_digits(n);
  str_length += digits;
  /*  printf("%d", digits); */
  printf("str_length = %d, ", str_length); 
    
  s = malloc(sizeof(char) * str_length);

  if (s == NULL)
    {
      return NULL;
    }

  i = str_length - 1;
  printf("i = %d", i); 
  s[i] = '\0';
  i--;
  
  if (was_negative)
    {
      s[0] = '-';
      while (i > 0)
	{
	  s[i] = n % 10;
	  printf(", n = %d, s[%d] = %c", n, i, s[i]); 
	  n /= 10;
	  i--;
	}
    }
  else
    {
      while (i >= 0)
	{
	  s[i] = n % 10;
	  n /= 10;
	  i--;
	}
    }
  
  return s;

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

/* int find_last_digit(int n)
{
  
} */

/* return number digits in an int */
int find_num_digits(int n)
{
  int i;

  for (i = 0; n > 0; i ++)
    {
      n = n / 10;
    }
  
  return i;
}
