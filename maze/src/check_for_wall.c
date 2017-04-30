#include <maze.h>

/* check if there is a wall at the coordinates we've specified */
int check_for_wall(int *coords, int start_x, int start_y, int delta_x, int delta_y, char (*map)[MAP_WIDTH]) {
    int found_wall = 0;
    int beyond_bounds = 0;
    int x = start_x;
    int y = start_y;
    int grid_x;
    int grid_y;

    while (!found_wall)
         {
             printf("current x: %i\n", x);
             printf("current y: %i\n", y);
            beyond_bounds =
                x > MAP_WIDTH_BOUND ||
                y > MAP_HEIGHT_BOUND ||
                x < 0 || y < 0;
            if (beyond_bounds) {
                printf("beyond bounds, breaking out of loop\n");
                break;
            }
             grid_x = x / CUBE_LENGTH;
             grid_y = y / CUBE_LENGTH;
             printf("grid_x: %i, grid_y: %i\n", grid_x, grid_y);
             printf("map[grid_y][grid_x]: %c\n", map[grid_y][grid_x]);
            if (map[grid_y][grid_x] == 'X') {
                found_wall = 1;
                coords[0] = x;
                coords[1] = y;
            } else {
                printf("did not find wall, repeating loop \n");
            }
            x += delta_x;
            y += delta_y;
         }

    return found_wall;
}
