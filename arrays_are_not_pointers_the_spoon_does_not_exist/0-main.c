void print_string_2(char *str);

int main(void)
{
  char *str;

  str = "0123456789\n"; /* this means I can read but not write elements of this string array, since the string is not stored in memory as a variable */
  print_string_2(str);
  return (0);
}
