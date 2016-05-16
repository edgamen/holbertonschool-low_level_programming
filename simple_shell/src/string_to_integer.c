#include <limits.h>

/* converts a string into an integer  */
int string_to_integer(char *s)
{
  int i;
  int sign;      /* track whether number should be positive or negative */
  int number;

  i = 0;
  number = 0;
  sign = 1;

  /* update sign until hitting first number */
  while (s[i] != '\0' && (s[i] < '0' || s[i] > '9')) {
      if (s[i] == '-') {
	  sign *= -1;
	}
      i ++;
    }

  /* store digits into an int until number ends */
  while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9')) {
      /* detect if storing number may cause int overflow */
    if (number > INT_MAX / 10) {
	  return (0);
	}
      if (number == INT_MAX / 10 && (s[i] - '0') > 7) {
	  if (sign == -1 && (s[i] - '0') == 8) {
	      return INT_MIN;
	    }
	  else {
	      return (0);
	    }
	}
      number = number * 10 + (s[i] - '0');
      i ++;
    }

  return sign * number;

}
