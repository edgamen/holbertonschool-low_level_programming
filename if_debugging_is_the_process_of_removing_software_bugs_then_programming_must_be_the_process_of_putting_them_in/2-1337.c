/* encodes a string into 1337 */
char *leet(char *string)
{
  int i;

  for (i = 0; string[i] != '\0'; i++)
    {
      if (string[i] == 'a' || string[i] == 'A')
	{
	  string[i] = '4';
	}
      
      else if (string[i] == 'e' || string[i] == 'E')
	{
	  string[i] = '3';
	}
      
      else if (string[i] == 'o' || string[i] == 'O')
	{
	  string[i] = '0';
	}
      
      else if (string[i] == 't' || string[i] == 'T')
	{
	  string[i] = '7';
	}

      else if (string[i] == 'l' || string[i] == 'L')
	{
	  string[i] = '1';
	}
          
    }

  return (string);
}
