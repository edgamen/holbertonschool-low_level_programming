#include "list.h"
#include <stdlib.h>

/* free contents of a doubly linked list */
void free_dl_list(List *list)
{
	List *current_node;
	List *next_node;

	current_node = list;

	while (current_node != NULL)
	{
		next_node = current_node->next;

		free(current_node->str);
		free(current_node);

		current_node = next_node;
	}
}
