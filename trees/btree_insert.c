#include <stdlib.h>
#include <string.h>
#include "tree.h"

BTree *create_new_node(char *data);
  
int btree_insert(BTree **tree, char *data)
{
  BTree *new_node;
  BTree *current_node;

  /* create a new node that we will store in the right position
     in the tree */
  new_node = create_new_node(data);
  /* in case of malloc failure, return error code */
  if (new_node == NULL)
    {
      return (-1);
    }

  /* if the root of the tree is empty, store the new node there */
  if (*tree == NULL)
    {
      *tree = new_node;
      return (0);
    }
  /* otherwise, traverse the tree to find the correct position */
  else
    {
      current_node = *tree;
      while (1)
	{
	  /* if string is less than current node we are comparing to,
	     we will place the new node in the current node's left branch
	     if it is empty, otherwise we'll move onto the left node and
	     compare our string to it */
	  if (strcmp(data, current_node->str) < 0)
	    {
	      if (current_node->left == NULL)
		{
		  current_node->left = new_node;
		  return (0);
		}
	      current_node = current_node->left;
	    }
	  /* if string is greater than or equal to the current node's str,
	     we will place the new node in the current node's right branch
	     if it is empty, otherwise we'll move onto the right node and
	     compare our string to it */
	  else
	    {
	        if (current_node->right == NULL)
		  {
		    current_node->right = new_node;
		    return (0);
		  }
		current_node = current_node->right;
	    }
	}
    }

  return (0);
}

/* Create a new BT node, with NULL for left/right branches */
BTree *create_new_node(char *data)
{
  BTree *new_node;

  /* allocate memory for the new node */
  new_node = malloc(sizeof(BTree));
  /* if malloc failed, return error code */
  if (new_node == NULL)
    {
      return new_node;
    }

  /* store the string into the node */
  new_node->str = strdup(data);
  /* if strdup failed, free malloced node and return err
     code */
  if (new_node->str == NULL)
    {
      free(new_node);
      return NULL;
    }

  /* set left and right nodes of new node to be empty pointers */
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}
