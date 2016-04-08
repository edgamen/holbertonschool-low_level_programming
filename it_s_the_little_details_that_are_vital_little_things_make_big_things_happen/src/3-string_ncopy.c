/* Copies a string, including the null-terminating byte */
char *string_ncopy(char *dest, const char *src, int n)
{
  int i = 0;
   
  for (i = 0; i < n && src[i] !='\0'; i++)
    {
      dest[i] = src[i];
    }
  
  for (; i < n; i++)
    {
      dest[i] = '\0';
    }

  return(dest);

}
