#include <stdio.h>
int is_a_number(char c);

int string_to_integer(char *s)
{
  int n, num;
  int negation_factor = 1;

  for (n = 0, num = 0; s[n] != '\0'; n++)
    {
      if (s[n] == '-')
	{
	negation_factor *= -1;
	}
      else if (is_a_number(s[n]))
	{
	  num = num * 10 + (s[n] - '0'); 

	 if (is_a_number(s[n + 1]) == 0)
	    {
		break;
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
