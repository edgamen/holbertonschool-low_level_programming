#include "my_functions.h"
#include <limits.h>

/* check if the argument is greater than INT_MAX */
int test_for_overflow(int n)
{
  if (n > INT_MAX)
    {
      return (-1);
    }
  else
    {
      return (1);
    }
}

/* prints P if arg is +, N if -, and Z if it is 0;
   takes an int */
void positive_or_not(int n)
{

  /* variable declarations */
  char s[] = "Error: int overflow";
  int i;

  /* variable initializations */
  i = 0;
  
  /* test for overflow cases */
  if (test_for_overflow(n) < 0)
    {
      while (s[i] != '\0')
	{
	  print_char(s[i]);
	  i ++;
	}
      print_char('\n');
    }
  
  /* in case of no error, print appropriate letter */
  else {
    if (n > 0)
      {
	print_char('P');
      }
    else if (n < 0)
      {
	print_char('N');
      }
    else
      {
	print_char('Z');
      }
  }
  
}
