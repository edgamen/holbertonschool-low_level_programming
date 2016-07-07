#include "hashtable.h"
HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);

int main(void)
{
	HashTable *hashtable;

	hashtable = ht_create(5);

	ht_put(hashtable, "testkey", "testvalue");
	ht_put(hashtable, "asdaskl", "testvalue2");
	ht_put(hashtable, "testkey", "testvalue3");
	return 0;
}
