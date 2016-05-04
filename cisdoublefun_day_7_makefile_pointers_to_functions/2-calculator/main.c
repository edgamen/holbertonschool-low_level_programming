#include <stdio.h>
#include <stdlib.h>

int check_arguments_valid(int ac);
int check_if_number(char *s);
int check_if_symbol(char *s);
int (*get_op_func(char c))(int, int);

/* a program that performs simple operations */
int main(int ac, char **av)
{
  int (*operation)(int, int);
  int first_number;
  int second_number;
  char symbol;
  int result;

  if (!check_arguments_valid(ac) ||
      !check_if_number(av[1]) ||
      !check_if_number(av[3]) ||
      !check_if_symbol(av[2]))
    {
      printf("Program exiting.\n");
      return (1);
      }

  first_number = atoi(av[1]);
  second_number = atoi(av[3]);
  symbol = av[2][0];

  /* select the appropriate function based on the operator symbol */
  operation = get_op_func(symbol);
  result = (*operation)(first_number, second_number);
  
  printf("%d\n", result);

  return (0);
}

/* check if the number of arguments is correct */
int check_arguments_valid(int ac)
{
   if (ac != 4)
    {
      printf("Err: Please supply the right number of arguments (a single operator and two numbers).\n");
      return (0);
    }

   return 1;
}

/* check if the number arguments are indeed numbers */
int check_if_number(char *s)
{
  int i;

  i = 0;

  if ( (s[i] >= '0' && s[i] <= '9') || s[i] == '-')
    {
      i++;
    }
  else
    {
      printf("Err: Please provide valid numbers, e.g. 9 or -9.\n");
      return (0);
    }
  
  while (s[i] != '\0')
    {
      if ( !(s[i] >= '0' && s[i] <= '9') )
	{
	  printf("Err: Please provide valid numbers, e.g. 9 or -9.\n");
	  return (0);
	}
      i++;
    }

  return 1;
}

/* check if the symbol argument is indeed a symbol */
int check_if_symbol(char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0')
    {
      if ( !(s[i] == '+' || s[i] == '-' ||
	     s[i] == '*' || s[i] == '/' ||
	     s[i] == '%') || i > 0)
	{
	  printf("Err: Please provide a single valid operator (+-*/%%).\n");
	  return (0);
	}
      i++;
    }

  return 1;
}
