int str_length(const char *s);
char *obtain_substring(int start_index, const char *src);

/* finds a substring in another string */
char *string_string(const char *haystack, const char *needle)
{
  int haystack_length;
  int needle_length;
  int start_index;
  int i, j;

  j = 0;
  haystack_length = str_length(haystack);
  needle_length = str_length(needle);
  
  while (i < haystack_length)
    {
      if (haystack[i] == needle[0])
	{
	  start_index = i;
	  while (haystack[i] == needle[j] && i < haystack_length)
	    {
	      if (j == needle_length)
		{
		  return obtain_substring(start_index, haystack);
		}
	      i++;
	      j++;
	    }
	  
	  /* if entire substring is not found, reset i and j values */
	  i = start_index;
	  j = 0;
	}
      i++;
    }
  
  return 0;
}

/* store substring in new string */
char *obtain_substring(int start_index, const char *src)
{
  char *substring;
  int i;
  int j;

  i = start_index;
  j = 0;

  while (src[i] != '\0')
    {
      substring[j] = src[i];
      i++;
      j++;
    }

  substring[j] = '\0';

  return substring;
}

/* finds the length of a string */
int str_length(const char *s)
{
  int i;

  i = 0;

  while (s[i] != '\0')
    {
      i++;
    }

  return i;
}
