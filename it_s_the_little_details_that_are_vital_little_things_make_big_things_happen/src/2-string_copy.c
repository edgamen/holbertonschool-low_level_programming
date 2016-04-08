#include <stdio.h>
int find_end(const char *str);

/* Copies a string, including the null-terminating byte */
char *string_copy(char *dest, const char *src)
{
  int i;
   
  for (i = 0; i <= find_end(src) + 1; i++)
    {
      dest[i] = src[i];
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
