#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

NTree *new_tree_node(char *data);

/* Insert a node into a N-ary tree */
int ntree_insert(NTree **tree, char **parents, char *data)
{
  NTree *new_node;
  NTree *parent;

  new_node = new_tree_node(data);
  if (new_node == NULL)
    {
      return (1);
    }
  /* debugging statements: 
     printf("String in root node: %s\n", (*tree)->str);
     printf("Addr of children list in root node: %p",	\
     (void *)((*tree)->children) ); 
  */

  /* Add new_node to root if the tree is empty */
  if (*tree == NULL)
    {
      *tree = new_node;
    }
  else
    {
      parent = find_parent_node(*tree, parents);
    }

  return (0);
}

/* Allocate memory for a new Ntree */
NTree *new_tree_node(char *data)
{
  NTree *new_node;
  
  new_node = malloc(sizeof(NTree));

  if (new_node == NULL)
    {
      return NULL;
    }

  /* Set to null as List is empty for now */
  new_node->children = NULL;

  /* Copy provided string into string member */
  new_node->str = strdup(data);
  if (new_node->str == NULL)
    {
      free(new_node);
      return NULL;
    }

  return new_node;
}

/* Find and return the parent node */
NTree *find_parent_node(Ntree *tree, char **parents)
{
  Ntree *current_tree_node;
  List *current_list;
  int i;

  current_tree_node = tree;
  i = 0;
  while (parents[i] != NULL)
    {
      printf("Item of array: %s, string in current tree node: %s\n", parents[i], current_tree_node->str)
      /* If the node string matches the first item in parents,
	 move onto next item in array and compare to strings
	 in children of node */
      if (strcmp(current_tree_node->str, parents[i]) == 0)
	{
	  printf("Matched; moving down a level to children and next array item\n");
	  current_list = current_tree_node->children;
	  current_tree_node = current_list->node;
	  i++;
	}
      /* If the node string does not match the array string,
	 check for the array string in the next node of the current
	 depth */
      else
	{
	  printf("Did not matching; moving onto the next node in this level\n");
	  current_list = current_list->next;
	  current_tree_node = current_list->node;
	}
    }

  printf("Next item in array is NULL, current tree node is: %s\n", current_tree_node->str);
  return current_tree_node;
}

/*List *new_list(List **head)
{
}*/
