#include <Astdlib.h>
#include "list.h"

char *string_dup(char *str);
int string_length(char *str);

/* allocates a new node and links it ot the list */
int add_node(List **list, char *content)
{
  List *node;

  node = malloc(sizeof(List));
  if (node == NULL)
    {
      return (1);
    }
  node->str = string_dup(content);
  if (node->str == NULL)
    {
      free(node);
      return (1);
    }

  node->next = *list;
  *list = node;

  return (0);  
}

/* returns a pointer to newly allocated space in memory
   which contains copy of string given as a param */
char *string_dup(char *str)
{

  char length;
  char *dup_string;
  int i;

  length = string_length(str);
  dup_string = malloc(sizeof(char) * length);

  /* if malloc fails, give an error */
  if (dup_string == NULL)
    {
      return NULL;
    }

  /* copy contents of original string into new string */
  for (i = 0; str[i] != '\0'; i++)
    {
      dup_string[i] = str[i];
    }

  /* copy the null char as well */
  dup_string[i] = str[i];

  return dup_string;
}

/* find the length of a given string */
int string_length(char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i ++)
    {
    }

  return ++i;
}
