#include <stdlib.h>
#include "list.h"
int print_char(char c);
void print_string(char *str);

/* print the contents of a list */
void print_dl_list(List *list)
{
	List *current_node;

	current_node = list;

	while (current_node != NULL)
	{
		print_string(current_node->str);
		print_char('\n');

		print_char('\t');
		if (current_node->prev != NULL) {
			print_string(current_node->prev->str);
		} else {
			print_string("NULL");
		}
		print_char('\n');

		print_char('\t');
		if (current_node->next != NULL) {
			print_string(current_node->next->str);
		} else {
			print_string("NULL");
		}
		print_char('\n');

		current_node = current_node->next;
	}
}
