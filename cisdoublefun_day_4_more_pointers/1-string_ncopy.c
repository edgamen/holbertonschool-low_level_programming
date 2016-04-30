/* copies a string, except that at most n bytes of src are copied.
   Warning:  If  there is no null byte among the first n bytes of src, 
   the string placed in dest will not be null-terminated.

   If the length of src is less than n, writes additional null
   bytes  to  dest  to   ensure that a total of n bytes are written. */
char *string_ncopy(char *dest, const char *src, int n)
{
  int i;

  i = 0;

  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i ++;
    }

  /* append additional null character bytes if src string 
     terminates before n characters are copied */
  while (i < n)
    {
      dest[i] = '\0';
      i++;
    }
  
  return dest;
  
}
