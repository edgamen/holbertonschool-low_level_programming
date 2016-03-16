int find_end(const char *str);

/* Copies a string, including the null-terminating byte */
char *string_ncopy(char *dest, const char *src, int n)
{
  int i;
   
  if (find_end(src) < n)
    {
      for (i = 0; src[i] !='\0'; i++)
	{
	  dest[i] = src[i];
	}
      for (i = find_end(src); i < n; i++)
	{
	  dest[i] = '\0';
	}
    }
  else
    {
      for (i = 0; i < n; i++)
	{
	  dest[i] = src[i];
	}
    }
     
  return(dest);

}

/* returns index of array that before terminating null byte '\0' */
int find_end(const char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i++)
    {
    }

  return (i);
}
