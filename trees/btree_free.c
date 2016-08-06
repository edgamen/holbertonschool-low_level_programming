#include <stdlib.h>
#include "tree.h"

/* Recursive function to free nodes in a binary tree */
void btree_free(BTree *tree)
{
  BTree *current_node;
  BTree *left_node;
  BTree *right_node;
  
  current_node = tree;
  left_node = tree->left;
  right_node = tree->right;

  free(current_node->str);
  free(current_node);

  if (left_node != NULL)
    {
      btree_free(left_node);
    }
  if (right_node != NULL)
    {
      btree_free(right_node);
    }
  
}
