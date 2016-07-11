#include "hashtable.h"
#include <stdlib.h>

/* Free everything malloced in a hashtable */
void ht_free(HashTable *hashtable)
{
	List *current_list;
	List *current_node;
	List *next_node;
	unsigned int i;

	/* go through array and free all nodes of Lists contained */
	for (i = 0; i < hashtable->size; i ++)
	{
		current_list = *(hashtable->array + i);

		for (current_node = current_list; \
		     current_node != NULL; current_node = next_node) {
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
		}
	}

	free(hashtable->array);
	free(hashtable);
}
