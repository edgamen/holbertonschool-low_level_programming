#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

NTree *new_tree_node(char *data);
NTree *find_parent_node(NTree *tree, char **parents);
int add_list_node(List **head, NTree *tree_node);
List *find_last_list_node(List *head);

/* Insert a node into a N-ary tree
   Return 0 on success, 1 on failure
*/
int ntree_insert(NTree **tree, char **parents, char *data)
{
  NTree *new_node;
  NTree *parent;

  new_node = new_tree_node(data);
  if (new_node == NULL)
    {
      return (1);
    }

  /* Add new_node to root if the tree is empty */
  if (*tree == NULL)
    {
      *tree = new_node;

      /* debugging statements: */
     printf("String in root node: %s\n", (*tree)->str);
     printf("Addr of children list in root node: %p\n",	\
     (void *)((*tree)->children) ); 

    }
  else
    {
      parent = find_parent_node(*tree, parents);

      /* Add a List node to the parent's children,
	 freeing memory and exiting in case of failure */
      if (add_list_node(&(parent->children), new_node) \
	  == 1)
	{
	  free(new_node->str);
	  free(new_node);
	  return (1);
	}

      /* debugging statements: */
      printf("Addr of parent tree node: %p\n",	\
	     (void *)(parent));
      printf("String in parent tree node: %s\n", parent->str);
      printf("Addr of children list of parent node: %p\n",	\
	 (void *)(parent->children));
      printf("String in first node of children list: %s\n",	\
	 parent->children->node->str);
      printf("Addr of next node in children list: %p\n",	\
	 (void *)(parent->children->next));

      if (parent->children->next != NULL)
	{
	  printf("String in next node of children list: %s\n",	\
	 parent->children->next->node->str);
	}
      printf("\n");

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

/* Add a node to the List; return 0 on success, 1 if error */
int add_list_node(List **head, NTree *tree_node)
{
  List *new_node;
  List *last_node;

  new_node = malloc(sizeof(List));
  if (new_node == NULL)
    {
      return (1);
    }
  new_node->node = tree_node;
  new_node->next = NULL;

  if (*head == NULL)
    {
      *head = new_node;
    }
  else
    {
      last_node = find_last_list_node(*head);
      last_node->next = new_node;
    }

  return (0);
}

/* Find the last node of a given List */
List *find_last_list_node(List *head)
{
  List *current_node;

  current_node = head;
  while (current_node->next != NULL)
    {
      current_node = current_node->next;
    }

  return current_node;
}

/* Find and return the parent node */
NTree *find_parent_node(NTree *tree, char **parents)
{
  NTree *current_tree_node;
  List *current_list;
  int i;

  current_tree_node = tree;
  i = 0;
  while (1)
    {
      printf("Item of array: %s, string in current tree node: %s\n", parents[i], current_tree_node->str);
      /* If the node string matches the current str in parents, and
	 it's the last item in array, break out of loop and return
	 current node */
      if (strcmp(current_tree_node->str, parents[i]) == 0 && \
	  parents[i + 1] == NULL)
	{
	  printf("Matched; next item in array is NULL; exiting loop\n");
	  break;
	}
      /* If the node string matches the current str in parents,
	 move onto next item in array and compare to strings
	 in children of node */
      else if (strcmp(current_tree_node->str, parents[i]) == 0) {
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
	  printf("Did not match; moving onto the next node in this level\n");
	  current_list = current_list->next;
	  current_tree_node = current_list->node;
	}
    }

  printf("Next item in array is NULL, current tree node is: %s\n", current_tree_node->str);
  return current_tree_node;
}
