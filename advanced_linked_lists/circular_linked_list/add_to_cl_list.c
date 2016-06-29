#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

List *find_last_node(List **list);

/* Add a node to the end of the list. If it fails, return 1; if it succeeds, return 0 */
int add_end_cl_list(List **list, char *str)
{
	List *new_node;
	List *prev_node;
	char *copied_str;

	copied_str = strdup(str);
	if (copied_str == NULL) {
		return (1);
	}

	new_node = malloc(sizeof(List));
	if (new_node == NULL) {
		free(copied_str);
		return (1);
	}

	new_node->str = copied_str;

	if (*list == NULL) {
		*list = new_node;
	} else {
		prev_node = find_last_node(list);
		prev_node->next = new_node;
	}

	new_node->next = *list;

	return (0);

}

/* Add a node to the beginning of the list. If it fails, return 1; if it succeeds, return 0 */
int add_begin_cl_list(List **list, char *str)
{
	List *new_node;
	List *last_node;
	char *copied_str;

	copied_str = strdup(str);
	if (copied_str == NULL) {
		return (1);
	}

	new_node = malloc(sizeof(List));
	if (new_node == NULL) {
		free(copied_str);
		return (1);
	}

	new_node->str = copied_str;

	if (*list == NULL) {
		printf("list is currently null! going to try add...");
		*list = new_node;
		new_node->next = *list;
	} else {
		new_node->next = *list;
		last_node = find_last_node(list);
		*list = new_node;
		last_node->next = *list;
	}

	return (0);

}

/* Go through the list until finding the last node */
List *find_last_node(List **list)
{

	List *current_node;

	current_node = *list;

	while (current_node->next != *list) {
		current_node = current_node->next;
	}

	return current_node;

}
