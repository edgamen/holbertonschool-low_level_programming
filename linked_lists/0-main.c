#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);

int main(void)
{
  List *list;

  printf("'list' is a pointer to the 'first' node in a list.\n");
  list = NULL;
  printf("The value of 'list', i.e. the addr to the 'first' node, is %p\n", (void *)list);

  printf("\nRunning add_node with 'Holberton' as string input.\n");
  if (add_node(&list, "Holberton") == 1)
    return (1);
  printf("The value of 'list', i.e. the addr to the 'first' node, is now %p.\n", (void *)list);
  printf("The string inside the 'first' node is %s.\n", list->str);


  printf("\nRunning add_node with 'School' as string input.\n");
  if (add_node(&list, "School") == 1)
    return (1);
  printf("The value of 'list', i.e. the addr to the 'first' node, is now %p.\n", (void *)list);
  printf("The string inside the 'first' node is %s.\n", list->str);

  return (0);
}
