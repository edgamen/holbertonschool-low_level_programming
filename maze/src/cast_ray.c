#include "maze.h"

/* Draw the maze */
int *cast_ray(int column_i)
{
    static int coords[3]; /* should be 2, not 3 */
    /* do mathy things and calculate length of line to draw) */
    coords[0] = WINDOW_HEIGHT / 4;
    coords[1] = WINDOW_HEIGHT / 4 * 3;
    /* do something with column i for now */
    coords[2] = column_i;

    return coords;
}
