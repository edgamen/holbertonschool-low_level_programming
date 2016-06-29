#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int add_begin_cl_list(List **, char *);

int main(void)
{
	List *list;

	list = NULL;

	printf("The address stored in list is %p.\n", (void *)list);
	printf("huh?");
	if (add_begin_cl_list(&list, "Holberton") == 1 ||
		add_begin_cl_list(&list, "School") == 1 ||
		add_begin_cl_list(&list, "Full") == 1 ||
		add_begin_cl_list(&list, "Stack") == 1 ||
		add_begin_cl_list(&list, "Engineer") == 1)
	{
		printf("there's an issue..");
		return (1);
	}


	printf("The address stored in list is now %p.\n", (void *)list);

	printf("The nodes in the list contain the strings:\n");
	/* printf("The next address is %p. \n", (void *)list->next);
	printf("It contains the string %s \n", list->next->str); */
	printf("%s\n", list->str);
	printf("%s\n", list->next->str);
	printf("%s\n", list->next->next->str);
	printf("%s\n", list->next->next->next->str);
	printf("%s\n", list->next->next->next->next->str);
	printf("%s\n", list->next->next->next->next->next->str);
	printf("%s\n", list->next->next->next->next->next->next->str);

	return (0);
}