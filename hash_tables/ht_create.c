#include <stdlib.h>
#include "hashtable.h"

/* Create a new HashTable with initialized variables */
HashTable *ht_create(unsigned int size) {
	HashTable *hashtable;
	List **array;

	hashtable = malloc(sizeof(HashTable));
	array = malloc(sizeof(List *) * size);
	hashtable->array = array;
	hashtable->size = size;

	return hashtable;
}
