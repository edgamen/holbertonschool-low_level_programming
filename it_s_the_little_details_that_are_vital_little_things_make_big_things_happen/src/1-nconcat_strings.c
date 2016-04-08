int find_end(const char *str);

/* Concatenates two strings. Will use at most n bytes from src. Size of dest must be at least the size of n + 1 (for null-terminating byte). */
char *nconcat_strings(char *dest, const char *src, int n)
{
  int end_of_dest = find_end(dest);
  int dest_index, src_index;
  int end_of_copy = find_end(src);

  if (end_of_copy > n)
    {
      end_of_copy = n;
    }
  
  for (dest_index = end_of_dest, src_index = 0; src_index < end_of_copy; src_index++, dest_index++)
    {
      dest[dest_index] = src[src_index];
    }
     
  return(dest);

}

/* returns index of array that is before terminating null byte '\0' */
int find_end(const char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i++)
    {
    }

  return (i);
}
