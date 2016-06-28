#include "list.h"
#include <stdlib.h>
#include <string.h>

List *find_last_node(List **list);

/* Add a node to the end of the list. If it fails, return 1; if it succeeds, return 0 */
int add_end_dl_list(List **list, char *str)
{
	List *new_node;
	List *prev_node;
	char *copied_str;

	new_node = malloc(sizeof(List));
	copied_str = strdup(str);
	if (new_node == NULL || copied_str == NULL) {
		return (1);
	}

	new_node->str = copied_str;
	new_node->next = NULL;

	if (*list == NULL) {
		*list = new_node;
		new_node->prev = NULL;
	} else {
		prev_node = find_last_node(list);
		prev_node->next = new_node;
		new_node->prev = prev_node;
	}

	return (0);

}

/* Add a node to the beginning of the list. If it fails, return 1; if it succeeds, return 0 */
int add_begin_dl_list(List **list, char *str)
{
	List *new_node;
	char *copied_str;

	new_node = malloc(sizeof(List));
	copied_str = strdup(str);
	if (new_node == NULL || copied_str == NULL) {
		return (1);
	}

	new_node->str = copied_str;
	new_node->prev = NULL;

	if (*list == NULL) {
		*list = new_node;
		new_node->next = NULL;
	} else {
		(*list)->prev = new_node;
		new_node->next = *list;
		*list = new_node;
	}

	return (0);

}

/* Go through the list until finding the last node */
List *find_last_node(List **list)
{

	List *current_node;

	current_node = *list;

	while (current_node->next != NULL) {
		current_node = current_node->next;
	}

	return current_node;

}
