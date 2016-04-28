#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

int string_to_integer(char *s)
{
  int i;
  int number;
  int first_number;      /* indicates this is the first number in string */
  int sign_factor;       /* track the sign of the number */ 

  first_number = 1;      /* set to true */
  sign_factor = 1;       /* set initial value to positive */ 
  i = 0;
  number = 0;
  
  while (s[i] != '\0')
    {
      if (s[i] >= '0' && s[i] <= '9')
	{
	  /* only add digit to number if this is still the first number */
	  if (first_number == 1)
	    {
	      if (number > (INT_MAX) / 10 || (number == INT_MAX / 10 && (s[i] - '0') > 7))
		{
		  printf("Error! INT_MAX = %d, number = %d, INT_MAX/10 = %d, s[i] = %d\n", INT_MAX, number, INT_MAX/10, s[i] - '0');
		  return (0);
		}
	      number = number * 10 + (s[i] - '0');

	      /* if the next char is not a number, the first number is finished */
	      if (s[i + 1] < '0' || s[i + 1] > '9')
		{
		  first_number = 0;
		}
	    }
	}
      else if (s[i] == '-' && first_number == 1)
	{
	  /* change the sign of the number */
	  sign_factor = sign_factor * (-1);
	}

        printf("current number is: %d\n", number * sign_factor);
	i ++;
    }

  return number * sign_factor;
}
