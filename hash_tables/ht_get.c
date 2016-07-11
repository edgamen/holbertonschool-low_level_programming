#include "hashtable.h"
#include <stdio.h>

int is_identical(const char *s1, const char *s2);

/* Retrieve the value for a specified key */
char *ht_get(HashTable *hashtable, const char *key)
{
	int index;
	List *list;
	List *current_node;

	index = hash(key, hashtable->size);
	list = *((hashtable->array) + index);

	/* search through nodes in list for key */
	for (current_node = list; \
	     current_node != NULL; \
	     current_node = current_node->next) {
		/* printf("current node key is %s and value is %s\n",	\
                   current_node->key, current_node->value); */

		if (is_identical(current_node->key, key)) {
			return current_node->value;
		}
	}

	return NULL;
}
