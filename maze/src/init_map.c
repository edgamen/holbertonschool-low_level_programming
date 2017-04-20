#include <string.h>

/* Return an array that represents the map */
char *init_map(void)
{
 /*
    For now we will just use an array that symbolizes the map
    Eventually we may take map data from command line or from a file location
 */
  char map[] = {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X',	'\n',
		'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'};
   
  return strdup(map);
}