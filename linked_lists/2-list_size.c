#include <stdlib.h>
#include "list.h"

/* returns the number of nodes in a list */
int list_size(List *list)
{
  int i;
  List *current;
  
  if (list == NULL)
    {
      return (0);
    }
  else
    {
      for (i = 1, current = list; current->next !=NULL; i++)
	{
	  current = current->next;
	}
    }

  return i;
}
