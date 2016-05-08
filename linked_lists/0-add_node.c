#include <stdlib.h>
#include "list.h"

char *string_dup(char *str);
int string_length(char *str);
List *create_new_node(char *content);

/* allocates a new node and links it to the list -- as the new head */
int add_node(List **list, char *content)
{
  List *new_node;

  new_node = create_new_node(content);
  if (new_node == NULL)
    {
      return (1);
    }

  /* set the next node of the new to be the next element in the rest of 
     the list (the previous head / current beginning of the list) */
  new_node->next = *list;
  /* now set the beginning of the list to be the new node  */
  *list = new_node;

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
