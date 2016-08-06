#include <string.h>
#include "tree.h"

/* Look for an element in a binatry tree; return node
   that contains string or NULL if string could not be found */
BTree *btree_find(BTree *tree, char *str)
{
  BTree *current_node;
  int res;
  
  current_node = tree;

  /* Continue searching until a string is found that matches */
  while ((res = strcmp(str, current_node->str)) != 0)
    {
      /* If our string is less than the string of the current node,
	 and the left node of current node is NULL, we could not
	 find our string in the appropriate place, so return NULL;
         if the left node exists, use that for next comparison */
      if (res < 0)
	{
	  if (current_node->left == NULL)
	    {
	      return NULL;
	    }
	  else
	    {
	      current_node = current_node->left;
	    }
	}
      /* If our string is greater than the string of the current node,
	 and the right node of current node is NULL, we could not
	 find our string in the appropriate place, so return NULL;
         if the right node exists, use that for next comparison */
      else
	{
	  if (current_node->right == NULL)
	    {
	      return NULL;
	    }
	  else
	    {
	      current_node = current_node->right;
	    }
	}
    }
  
  return current_node;
  
}

/* Another way would be using recursion -- what is the big O notation
   for both versions, for this function and inserting an element? */
