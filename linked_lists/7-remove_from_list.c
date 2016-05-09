#include <stdlib.h>
#include "list.h"

void remove_from_list(List **list, int index)
{
  List *preceding_node;
  List *node_to_be_freed;
  int i;
  
  if (index == 0)
    {
      free((*list)->str);
      free(*list);
      return;
    }
  
  preceding_node = *list;
  /* find node that should precede the node to be removed */
  for (i = 1; i < index && preceding_node->next != NULL; i++)
    {
      preceding_node = preceding_node->next;
    }

  /* if nothing is located at the index: */
  if (preceding_node->next == NULL)
    {
      return;
    }
  else
    {
      node_to_be_freed = preceding_node->next;
      preceding_node->next = node_to_be_freed->next;
      free(node_to_be_freed->str);
      free(node_to_be_freed);
    }
  
}
