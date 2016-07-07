#include <stdlib.h>
#include "hashtable.h"

/* Create a new HashTable with initialized variables */
HashTable *ht_create(unsigned int size)
{
	HashTable *hashtable;
	List **array;
	unsigned int i;

	hashtable = malloc(sizeof(HashTable));
	array = malloc(sizeof(List *) * size);
	hashtable->array = array;
	hashtable->size = size;

	/* set the head to be null for all of List in array */
	for (i = 0; i < size; i ++)
	{
		*(array + i) = NULL;
	}

	return hashtable;
}
