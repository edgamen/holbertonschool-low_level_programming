int str_len(char *str);

/* concatenates two strings */
char *string_nconcat(char *dest, const char *src, int n)
{
  int i;
  int j;

  i = str_len(dest);
  j = 0;

  while (src[j] != '\0' && j < n)
    {
      dest[i] = src[j];
      i++;
      j++;
    }

  dest[i] = '\0';

  return dest;
  
}

/* returns the length of a string */
int str_len(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
    }

  return (n);
}

