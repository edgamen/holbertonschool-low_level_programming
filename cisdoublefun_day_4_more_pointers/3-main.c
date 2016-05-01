#include <stdio.h>
char *string_string(const char *haystack, const char *needle);

int main(void)
{
  const char *haystack;
  char *substring;

  haystack = "I am a big haystack with a needle inside. But not a big needle.\n";
  
  substring = string_string(haystack, "needle");
  printf("%s", haystack);
  printf("%s", substring);
  return (0);
}
