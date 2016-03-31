int find_length(int x, char *s);
int test_letters(int start_index, int end_index, char *s);

/* return 1 if string is a palindrome and 0 if not */
int is_palindrome(char *s)
{
  int start_index = 0;
  int end_index = find_length(0, s);

  return test_letters(start_index, end_index, s);
}

/* Find number of elements that are not null, counting from 0 */
int find_length(int x, char *s)
{
  if (s[x + 1] == '\0')
    {
      return (x);
    }
  else return find_length(x + 1, s);
}

/* test if corresponding letters match, recursively */
int test_letters(int start_index, int end_index, char *s)
{
  if (start_index == end_index || start_index > end_index)
    {
      return (1);
    }
  else if (s[start_index] != s[end_index])
    {
      return (0);
    }
  else 
    {
      return test_letters(start_index + 1, end_index - 1, s);
    }
}

