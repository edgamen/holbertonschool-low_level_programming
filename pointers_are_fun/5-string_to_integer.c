#include <stdio.h>
int is_a_number(char c);

int string_to_integer(char *s)
{
  int n, num;
  int negation_factor = 1;
  int first_number = 1;

  for (n = 0, num = 0; s[n] != '\0' && first_number == 1; n++)
    {
      if (s[n] == '-' && first_number == 1)
	{
	negation_factor *= -1;
	}
      else if (is_a_number(s[n]) && first_number == 1)
	{
	  num = num * 10 + (s[n] - '0'); 

	 if (is_a_number(s[n + 1]) == 0)
	    {
		first_number = 0;
	    }
 	}
    }

  num = num * negation_factor;    
  printf("%d\n", num);
 
  return (0);
}

int is_a_number(char c) {
  return (c >= '0'&& c <= '9');
}
