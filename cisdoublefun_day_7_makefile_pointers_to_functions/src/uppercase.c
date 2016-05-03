/* convert letters to upper case if possible */
char uppercase(char c) {
  char conv = 'a' - 'A';

  if (c >= 'a' && c <= 'z') {
    return (c - conv);
  }
  else {
    return (c);
  }
}
