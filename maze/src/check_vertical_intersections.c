#include "maze.h"
#include <stdlib.h>
#include <math.h>

int check_vertical_intersections(int *vertical_coords, int ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH])
{
    int current_x;
    int current_y;
    int grid_x;
    int grid_y;
    int delta_x;
    int delta_y;
    int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
    int ray_vertical = ray_angle == 90 || ray_angle == 270;
    int ray_facing_right = ray_angle < 90 || ray_angle > 270;
    int ray_facing_left = ray_angle > 90 && ray_angle < 270;
    int ray_facing_up = ray_angle > 0 && ray_angle < 180;
    int found_wall = 0;
    int beyond_bounds = 0;

    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("ray angle: %i\n", ray_angle);
        printf("horizontal coords x: %i\n", vertical_coords[0]);
        printf("horizontal coords y: %i\n", vertical_coords[1]);
        printf("map[0][0] %c\n", map[0][0]);
    } else if (DEBUG) {
        printf("%s\n", "====== START CHECK_VERTICAL_INTERSECTIONS =====");
        printf("ray angle: %i\n", ray_angle);
    }

    if (ray_vertical)
    {
        return 0;
    }
    else if (ray_facing_right)
    {
        current_x = floor(player->x_coord / CUBE_LENGTH) * CUBE_LENGTH
            + CUBE_LENGTH;
    }
    else if (ray_facing_left) {
        current_x = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - 1;
    } else {
        printf("warning! ray_angle %i is over 360 degrees, did not handle the case\n", ray_angle);
        return 0;
    }
    if (ray_facing_up) {
        current_y = player->y_coord + (player->x_coord - current_x)/tan(ray_angle);
    } else {
        current_y = player->y_coord + (current_x - player->x_coord)/tan(ray_angle);
    }

    delta_x = ray_facing_right ? CUBE_LENGTH : -CUBE_LENGTH;
    delta_y = ray_horizontal ? 0 : CUBE_LENGTH*tan(ray_angle);

    /* check if there is a wall at the coordinates we've specified */
    while (!found_wall)
         {
             printf("current x: %i\n", current_x);
             printf("current y: %i\n", current_y);
            beyond_bounds =
                 current_x > MAP_WIDTH_BOUND ||
                 current_y > MAP_HEIGHT_BOUND ||
                 current_x < 0 || current_y < 0;
            if (beyond_bounds) {
                printf("MAP_WIDTH_BOUND %i\n", MAP_WIDTH_BOUND);
                printf("MAP_LENGTH_BOUND %i\n", MAP_HEIGHT_BOUND);
                printf("beyond bounds, breaking out of loop\n");
                break;
            }
             grid_x = current_x / CUBE_LENGTH;
             grid_y = current_y / CUBE_LENGTH;
             printf("grid_x: %i, grid_y: %i\n", grid_x, grid_y);
             printf("map[grid_y][grid_x]: %c\n", map[grid_y][grid_x]);
            if (map[grid_y][grid_x] == 'X') {
                found_wall = 1;
                vertical_coords[0] = current_x;
                vertical_coords[1] = current_y;
            } else {
                printf("did not find wall, repeating loop \n");
            }
            current_x += delta_x;
            current_y += delta_y;
         }

    printf("====== END CHECK_VERTICAL_INTERSECTIONS; found_wall = %i, x %i, y %i ===== \n",
    found_wall, vertical_coords[0], vertical_coords[1]);
    return found_wall;
}
