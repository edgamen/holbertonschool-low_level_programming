#include "list.h"
#include <stdlib.h>

/* frees each node and its malloced string in a list */
void free_list(List *list)
{
  List *current_node;
  List *next_node;

  if (list==NULL)
    {
      return;
    }

  for (current_node = list; current_node != NULL; current_node = next_node)
    {
      free(current_node->str);
      next_node = current_node->next;
      free(current_node);
    }

}
