#include <stdlib.h>
#include "list.h"

void print_string(char *str);
int print_char(char c);
int list_size(List *list);

/* print each element of a list */
void print_list(List *list)
{
  int i;
  List *current;
  int size;

  size = list_size(list);

  if (size != 0)
    {
      /* print the first element */
      print_string(list->str);
    }

  /* print the rest of the rest of the list */
  for (i = 1, current = list->next; i < size; i++)
    {
      print_char(',');
      print_char(' ');
      print_string(current->str);
      current = current->next;
    }

  print_char('\n');
}

/* returns the number of nodes in a list */
int list_size(List *list)
{
  int i;
  List *current;

  if (list == NULL)
    {
      return (0);
    }
  else
    {
      for (i = 1, current = list; current->next !=NULL; i++)
	{
	  current = current->next;
	}
    }

  return i;
}

/* prints a string */
void print_string(char *str)
{
  int n;

  for (n = 0; str[n] != '\0'; n++)
    {
      print_char(str[n]);
    }
}

