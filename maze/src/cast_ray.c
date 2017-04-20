#include "maze.h"

/* Draw the maze */
int *cast_ray(int column_i)
{
    static int coords[2];
    /* do mathy things and calculate length of line to draw) */
    if ((column_i >= 0 && column_i <= 40) ||
        (column_i >= (WINDOW_WIDTH - 40) && column_i <= (WINDOW_WIDTH)))
    {
        coords[0] = 0;
        coords[1] = 0;
    }
    else
    {
        coords[0] = WINDOW_HEIGHT / 4;
        coords[1] = WINDOW_HEIGHT / 4 * 3;
    }


    return coords;
}
