#include <stdio.h>
int find_end(const char *str);

/* Copies a string, including the null-terminating byte */
char *string_ncopy(char *dest, const char *src, int n)
{
  int dest_index, src_index;
   
  for (dest_index = 0, src_index = 0; src_index <= find_end(src) + 1; src_index++, dest_index++)
    {
      dest[dest_index] = src[src_index];
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
