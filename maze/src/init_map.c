#include <string.h>

/* Return an array that represents the map */
char (*init_map(void)) [MAP_WIDTH][MAP_HEIGHT]
{
    /*
    For now we will just use an array that symbolizes the map
    Eventually we may take map data from command line or from a file location
    */
  char map[MAP_WIDTH][MAP_HEIGHT] = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };

  return strdup(map);
}
