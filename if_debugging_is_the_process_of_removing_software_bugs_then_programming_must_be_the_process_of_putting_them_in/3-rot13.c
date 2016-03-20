/* encodes a string using rot13 */
char *rot13(char *string)
{
  int i;

  for (i = 0; string[i] != '\0'; i++)
    {
      if (string[i] >= 'a' &&  string[i] <= 'z') 
	{
	  if (string[i] > ('z' - 13))
	    {
	      string[i] = ('a' - 1) + (string[i] + 13 - 'z');
	    }

	  else
	    {
	      string[i] = string[i] + 13;
	    }
	}

       else if (string[i] >= 'A' && string[i] <= 'Z')
	{
	  string[i] = string[i] + 13;

	  if (string[i] > 'Z')
	    {
	      string[i] = ('A' - 1) + (string[i] - 'Z');
	    }
	}
    }
  
  return (string);
}
