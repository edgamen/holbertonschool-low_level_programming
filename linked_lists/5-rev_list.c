#include <stdlib.h>
#include "list.h"

/* reverses the order of the nodes in the list */
void rev_list(List **list)
{
  List *current_node;
  List *next_node;
  List *previous_node;

  current_node = *list;
  if (current_node == NULL)
    {
      return;
    }
  next_node = current_node->next;
  current_node->next = NULL;
  
  for (previous_node = current_node; next_node != NULL; )
    {
      current_node = next_node;
      next_node = current_node->next;
      current_node->next = previous_node;
      previous_node = current_node;
    }

  /*return current_node;*/
  *list = current_node;
}
