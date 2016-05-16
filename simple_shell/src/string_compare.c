/* returns whether the strings are identical (1) or not (0)
   traditionally will return whether s1 is greater or less than
   s2 but don't need this functionality in our program */
int string_compare(char *s1, char *s2)
{
  int i;

  for (i = 0; s1[i] !='\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return (0);
    }
  }

  if (s1[i] != '\0' || s2[i] != '\0') {
      return (0);
  }

  return (1);
}
