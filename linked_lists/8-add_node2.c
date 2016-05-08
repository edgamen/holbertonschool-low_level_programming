#include <stdlib.h>
#include "list.h"

char *string_dup(char *str);
int string_length(char *str);
List *find_last_node(List **list);
List *create_new_node(char *content);

/* allocates a new node and links it to the list -- at the end */
int add_node(List **list, char *content)
{
  List *new_node;
  List *last;

  new_node = create_new_node(content);
  if (new_node == NULL)
    {
      return (1);
    }
  new_node->next = NULL;

  /* if this is the first node: */
  if (*list == NULL)
    {
      *list = new_node;
    }
  else
    {
      /* find the last node and designate the new node to follow */
      last = find_last_node(list);
      last->next = new_node;
    }

  return (0);  
}

List *create_new_node(char *content)
{
  List *node;

  node = malloc(sizeof(List));
  /* seems redundant so I commented it out:
   * if (node == NULL) 
   * {
   *   return NULL;
   * } 
   */
  node->str = string_dup(content);
  if (node->str == NULL)
    {
      free(node);
      return (NULL);
    }

  return node;  
}

/* not sure yet if we need content for this function*/
List *find_last_node(List **list)
{
  List *last;

  last = *list;

  while (last->next !=NULL)
    {
      last = last->next;
    }

  return last;
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
