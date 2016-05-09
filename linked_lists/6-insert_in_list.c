#include <stdlib.h>
#include "list.h"

char *string_dup(char *str);
int string_length(char *str);
List *find_last_node(List **list);
int list_size(List *list);
List *create_new_node(char *content);
int append_node(List **list, char *content);
int add_node(List **list, char *content);

/* creates a node and then inserts it in a list at a specific index */
int insert_in_list(List **list, char *content, int index)
{
  List *new_node;
  List *preceding_node;
  int i;

  /* if the index is not valid, do nothing and ret 0 */
  if (index < 0)
    {
      return (0);
    }
  if (index == 0)
    {
      /* add a node at the beginning of the list
         and return whether it was successful or not */
      return add_node(list, content);
    }
  
  preceding_node = *list;
  /* find node that should precede the new node */
  for (i = 1; i < index && preceding_node->next != NULL; i++)
    {
      preceding_node = preceding_node->next;
    }

  /* if the index is greater than the list size: 
     just add a node  at the end of the list */
  if (preceding_node->next == NULL)
    {
      /* return whether it was successful or not */
      return append_node(list, content);
    }
  
  else
    {
      new_node = create_new_node(content);

      /* if allocating space for a new node and its contents 
	 was unsuccessful: */
      if (new_node == NULL)
	{
	  return (1);
	}

      new_node->next = preceding_node->next;
      preceding_node->next = new_node;
    }

  return (0);
}

/* allocates a new node and links it to the list -- at the end */
int append_node(List **list, char *content)
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

/* find the last node in a list */
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
