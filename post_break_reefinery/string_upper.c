#include <stdio.h>

int string_upper(char *s);

int main(int ac, char **av)
{

  char *s;
  
  /* in case the provided string is empty */
  if (ac == 1)
    {
      printf("Please provide a string to analyze.\n");
      printf("Program exiting.\n");
      return (1);
    }
  else if (ac != 2)
    {
      printf("Please provide just a single string (use "" or '' for a string with multiple words).\n");
      printf("Program exiting.\n");
      return (1);
    }

  s = av[1];
  if (string_upper(s))
    {
      printf("The string only contains upper-case alphabetical characters.\n");
    }
  else
    {
      printf("The string does not only contain upper-case alphabetical characters.\n");
    }

  return (0);
}

/* check if string only contains uppercase alphabetical characters */
int string_upper(char *s)
{
  int i;

  for (i = 0; s[i] != '\0'; i++)
    {
      if (s[i] < 'A'  || s[i] > 'Z')
	{
	  return (0);
	}
    }

  return (1);
}
