/* return the absolute value of an integer */

int absolute(int n) {
  if (n < 0)
    {
      return (n * -1);
    }
  else {
    return (n);
  }
}

char uppercase(char c) {
  char conv = 'a' - 'A';

  if (c >= 'a' && c <= 'z') {
    return (c - conv);
  }
  else {
    return (c);
  }
}
