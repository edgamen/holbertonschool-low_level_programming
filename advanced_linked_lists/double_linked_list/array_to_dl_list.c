#include "list.h"
#include <stdlib.h>

int add_end_dl_list(List **, char *);

/* convert an array of strings to a linked list */
List *array_to_dl_list(char **array)
{
	List *list;
	int i;

	list = NULL;

	for (i = 0; array[i] != NULL; i++)
	{
		if (add_end_dl_list(&list, array[i]) == 1)
		{
			return NULL;
		}
	}

	return list;
}
