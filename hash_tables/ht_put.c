#include "hashtable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int hash(const char *key, unsigned int size);
int add_node(List **head, const char *key, const char *value);
int is_identical(const char *s1, const char *s2);

/* Add a new element to the hashtable */
int ht_put(HashTable *hashtable, const char *key, const char *value)
{
	int index;
	List *current_node;

	index = hash(key, hashtable->size);
	/* printf("index is %d\n", index); */

	/* if key already used, replace existing value with new value and exit function */
	for (current_node = *((hashtable->array) + index);	\
	     current_node != NULL; \
	     current_node = current_node->next) {
		/* printf("current node %p is not null\n", (void *)current_node);
		   printf("current node key is %s and value is %s\n", \
		   current_node->key, current_node->value); */

		if (is_identical(current_node->key, key)) {
			/* printf("key %s is already used\n", key); */
			free(current_node->value);
			current_node->value = strdup(value);
			/* printf("%s is now the value of %p\n", current_node->value, \
			   (void *)current_node); */
			if (current_node->value == NULL) {
				return 1;
			}

			return 0;
		}
	}


	/* otherwise, add a new node to the list */
	if (add_node(((hashtable->array) + index), key, value) == 1) {
		return 1;
	}

	return 0;
}

/* add a node to list */
int add_node(List **head, const char *key, const char *value)
{
	List *new_node;
	new_node = malloc(sizeof(List));
	if (new_node == NULL) {
		return 1;
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL) {
		free(new_node);
		return 1;
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL) {
		free(new_node->key);
		free(new_node);
		return 1;
	}

	if (*head == NULL) {
		/* printf("current head of this node is NULL\n");
		   printf("address of head %p\n", (void*)*head); */
		new_node->next = NULL;
	} else {
		new_node->next = *head;
	}

	*head = new_node;
	/* printf("address of head is now %p\n", (void*)*head); */

	/* printf("adding new node %p, with key %s and value %s\n", \
	   (void *)new_node, new_node->key, new_node->value); 
	if (new_node->next == NULL) {
		printf("new node next is NULL\n");
	} else {
		printf("new node next is %p with key %s and value %s\n", \
		(void *)new_node->next, (new_node->next)->key, (new_node->next)->value);
	} */
	return 0;
}

/* check if two strings are identical */
int is_identical(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0; i++) {
	}

	if (s1[i] == 0 && s2[i] == 0) {
		return 1;
	}

	return 0;
}
