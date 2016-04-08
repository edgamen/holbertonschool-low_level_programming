int find_end(char *str);

/* Concatenates dest string and src string by overwriting null terminating char of dest string with contents of src string. Dest string must have enough space to contain src string. */
char *concat_strings(char *dest, const char *src)
{
  int end_of_dest = find_end(dest);
  int dest_index, src_index;
  
  for (dest_index = end_of_dest, src_index = 0; src[src_index] != '\0'; src_index++, dest_index++)
    {
      dest[dest_index] = src[src_index];
    }

  /* append a null-terminating string at end of new dest string 

  if (dest[dest_index + 1] == '\0')
    {
      printf("\\0 is at end of new dest string");
    }
  else
    {
      printf("\\0 is not at the end of new dest string");
      dest[dest_index + 1] = '\0'; 
    } */
  
    return(dest);
  
}

/* returns index of array that is terminating null byte '\0' */
int find_end(char *str)
{
  int n;

  for (n = 1; str[n] != '\0'; n++)
    {
    }

  return (n);
}

 
