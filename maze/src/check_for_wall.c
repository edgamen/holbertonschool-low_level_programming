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
             printf("current x: %f\n", x);
             printf("current y: %f\n", y);
            beyond_bounds =
                x > MAP_WIDTH_BOUND ||
                y > MAP_HEIGHT_BOUND ||
                x < 0 || y < 0;
            if (beyond_bounds) {
                printf("MAP_WIDTH_BOUND %f\n", MAP_WIDTH_BOUND);
                printf("MAP_HEIGHT_BOUND %f\n", MAP_HEIGHT_BOUND);
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
