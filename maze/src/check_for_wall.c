#include <maze.h>

/* check if there is a wall at the coordinates we've specified */
int check_for_wall(float *coords, float start_x, float start_y, float delta_x, float delta_y, char (*map)[MAP_WIDTH]) {
    int found_wall = 0;
    int beyond_bounds = 0;
    float x = start_x;
    float y = start_y;
    int grid_x;
    int grid_y;

    while (!found_wall)
         {
            if (DEBUG_DEFAULT)  printf("current x: %f\n", x);
            if (DEBUG_DEFAULT)  printf("current y: %f\n", y);
            beyond_bounds =
                x > MAP_WIDTH_BOUND ||
                y > MAP_HEIGHT_BOUND ||
                x < 0 || y < 0;
            if (beyond_bounds) {
                if (DEBUG_DEFAULT) printf("MAP_WIDTH_BOUND %f\n", MAP_WIDTH_BOUND);
                if (DEBUG_DEFAULT) printf("MAP_HEIGHT_BOUND %f\n", MAP_HEIGHT_BOUND);
                if (DEBUG_DEFAULT) printf("beyond bounds, breaking out of loop\n");
                break;
            }
             grid_x = x / CUBE_LENGTH;
             grid_y = y / CUBE_LENGTH;
             if (DEBUG_DEFAULT) printf("grid_x: %i, grid_y: %i\n", grid_x, grid_y);
             if (DEBUG_DEFAULT) printf("map[grid_y][grid_x]: %c\n", map[grid_y][grid_x]);
            if (map[grid_y][grid_x] == 'X') {
                found_wall = 1;
                coords[0] = x;
                coords[1] = y;
            } else {
                if (DEBUG_DEFAULT) printf("did not find wall, repeating loop \n");
            }
            x += delta_x;
            y += delta_y;
         }

    return found_wall;
}
