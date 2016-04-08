/* capitalizes all words of string */
char *cap_string(char *string)
{
  int i;

  for (i = 0; string[i] != '\0'; i++)
    {
      if (i == 0 || string[i - 1] == ' ' || string[i - 1] == '\n' || string[i - 1] == '\t')
        {
	  if (string[i] >= 'a' && string[i] <= 'z')
	    {
	      string[i] = string[i] - ('a' - 'A');
	    }
        }
    }

  return (string);
}
