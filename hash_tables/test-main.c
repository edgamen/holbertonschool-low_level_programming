#include "hashtable.h"
#include <stdio.h>
HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
char *ht_get(HashTable *hashtable, const char *key);
void ht_free(HashTable *hashtable);

int main(void)
{
	HashTable *hashtable;

	hashtable = ht_create(5);

	ht_put(hashtable, "testkey", "testvalue");
	ht_put(hashtable, "asdaskl", "testvalue2");
	ht_put(hashtable, "testkey", "testvalue3");

	printf("Getting value for asdaskl... %s\n", ht_get(hashtable, "asdaskl"));
	ht_free(hashtable);
	return 0;
}
