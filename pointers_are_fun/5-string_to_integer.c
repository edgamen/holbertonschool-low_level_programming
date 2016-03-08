#include <stdio.h>
int is_a_number(char c);

/* Convert the first number in a string to an int */
int string_to_integer(char *s)
{
  int n, num;
  int negation_factor = 1;

  for (n = 0, num = 0; s[n] != '\0'; n++)
    {
      if (s[n] == '-') /* Keep track of whether or not the number should be negative */
	{
	negation_factor *= -1;
	}
      else if (is_a_number(s[n]))
	{
	  num = num * 10 + (s[n] - '0'); /* Add each digit in 1st digit, multiplying by 10 to keep proper place */

	 if (is_a_number(s[n + 1]) == 0)
	    {
	      break;    /* if first number is ending, discontinue for loop */
	    }
 	}
    }

  /* Multiply number by neg factor in case it should be negative before returning */   
  num = num * negation_factor; 
 
  return (num);
}

/* Return whether the provided value is a digit char or not */
int is_a_number(char c) {
  return (c >= '0'&& c <= '9');
}
