/* changes all lowercase letters of a string to uppercase */
char *uppercase_string(char * string)
{
  int i;

  for (i = 0; string[i] != '\0'; i++)
    {
      if (string[i] >= 'a' && string[i] <= 'z')
	{
	  string[i] = string[i] - ('a' - 'A');
	}

    }

  return (string);
}
