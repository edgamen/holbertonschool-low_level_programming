#include <stdlib.h>
#include "tree.h"

int ntree_insert(NTree **, char **, char *);

int main(void)
{
  NTree *tree;
  char **array;

  tree = NULL;
  ntree_insert(&tree, NULL, "/");
}
