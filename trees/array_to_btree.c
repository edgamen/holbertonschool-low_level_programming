#include <stdlib.h>
#include "tree.h"

int btree_insert(BTree **tree, char *data);

/* Convert an array of strings into a binary tree 
   Assumes the array is NULL-terminated */
BTree *array_to_btree(char **array)
{
  BTree *root;
  int i;

  root = NULL;
  
  for (i = 0; array[i] != NULL; i++)
    {
      if (btree_insert(&root, array[i]) == -1)
	{
	  return NULL;
	}
    }

  return root;
}
