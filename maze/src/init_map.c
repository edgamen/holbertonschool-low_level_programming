#include <string.h>
#include <maze.h>

/* Return an array that represents the map */
char (*init_map(void))[MAP_WIDTH]
{
    /*
    For now we will just use an array that symbolizes the map
    Eventually we may take map data from command line or from a file location
    */
  static char map[MAP_HEIGHT][MAP_WIDTH] = {
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

  return map;
}

/*
char input[] = {
      'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', '\n',
      'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'
  };
*/
