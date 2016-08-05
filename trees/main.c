#include "tree.h"
#include <stdlib.h>

int btree_insert(BTree **tree, char *data);

int main(void)
{
  BTree *tree;
  
  tree = NULL;
  btree_insert(&tree, "Here");
  btree_insert(&tree, "is");
  btree_insert(&tree, "Holberton!");

  return (0);
}
