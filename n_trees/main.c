#include <stdlib.h>
#include "tree.h"

char **string_split(const char *string, char separator);

int ntree_insert(NTree **, char **, char *);

int main(void)
{
  NTree *tree;
  char **array;

  tree = NULL;
  ntree_insert(&tree, NULL, "/");
  ntree_insert(&tree, (array = string_split("/", ' ')), "tmp");
  ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file");
  ntree_insert(&tree, (array = string_split("/ tmp", ' ')), "tmp_file2");
  ntree_insert(&tree, (array = string_split("/", ',')), "mnt");
  ntree_insert(&tree, (array = string_split("/ mnt", ' ')), "HDD1");

  return (0);
}
