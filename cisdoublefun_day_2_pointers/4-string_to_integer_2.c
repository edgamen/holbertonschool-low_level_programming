#include <limits.h>
1;95;0c
int string_to_integer(char *s)
{
  int i;
  int sign;
  int number;

  i = 0;
  number = 0;
  sign = 1;
  
  while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
    {
      if (s[i] == '-')
	{
	  sign *= -1;
	}
      i ++;
    }

  while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
    {
      if (number > INT_MAX / 10)
	{
	  return (0);
	}
      if (number == INT_MAX / 10 && (s[i] - '0') > 7)
	{
	  if (sign == -1 && (s[i] - '0') == 8)
	    {
	      return INT_MIN;
	    }
	  else
	    {
	      return (0);
	    }
	}
      number = number * 10 + (s[i] - '0');
      i ++;
    }

  return sign * number;
	 
}
