#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
BTree *btree_find(BTree *tree, char *str);
BTree *array_to_btree(char **array);
void btree_free(BTree *tree);

int main(void)
{
  BTree *tree;
  BTree *a_node;
  char *strings[] = {"Here", "is", "Holberton!", NULL};
  
  /* tree = NULL;
  btree_insert(&tree, "Here");
  btree_insert(&tree, "is");
  btree_insert(&tree, "Holberton!"); */

  tree = array_to_btree(strings);
  if (tree == NULL)
    {
      printf("error");
      return (-1);
    }
  
  a_node = btree_find(tree, "afab");
  if (a_node != NULL)
    {
        printf("Found string: %s\n", a_node->str);
    }
  else
    {
      printf("Couldn't find anything\n");
    }
  a_node = btree_find(tree, "Holberton!");
  if (a_node != NULL)
    {
        printf("Found string: %s\n", a_node->str);
    }
  else
    {
      printf("Couldn't find anything\n");
    }

  btree_free(tree);
  
  return (0);
}
