/* 
#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);

int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "Holberton") == 1)
    return (1);
  if (add_node(&list, "School") == 1)
    return (1);
  return (0);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);
List *find_last_node(List **list);

int main(void)
{
  List *list;
  struct List *ptr_to_current_tail;

  printf("'list' is a pointer to the 'first' node in a list.\n");
  list = NULL;
  printf("'list', i.e. the ptr to the 'first' node, is %p\n", (void *)list);

  printf("\nRunning add_node with 'Holberton' as string input.\n");
  if (add_node(&list, "Holberton") == 1)
    return (1);
  printf("'list', i.e. the ptr to the 'first' node, is now %p.\n", (void *)list);
  printf("The string in the head of the list is %s\n", list->str);
  ptr_to_current_tail = find_last_node(&list);
  printf("ptr_to_current_tail is %p\n", (void *)ptr_to_current_tail);
  printf("The string in the current tail of the list is %s\n", ptr_to_current_tail->str);

  printf("\nRunning add_node with 'School' as string input.\n");
  if (add_node(&list, "School") == 1)
    return (1);
  printf("'list', i.e. the ptr to the 'first' node, is still %p.\n", (void *)list);
  printf("The string in the head of the list is still %s\n", list->str);
  ptr_to_current_tail = find_last_node(&list);
  printf("ptr_to_current_tail is now %p\n", (void *)ptr_to_current_tail);
  printf("The string in the current tail of the list is %s\n", ptr_to_current_tail->str);

  return (0);
} 
