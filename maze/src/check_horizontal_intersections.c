#include "maze.h"
#include <stdlib.h>
#include <math.h>

int check_horizontal_intersections(int *horizontal_coords, int ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH])
{
    int current_x;
    int current_y;
    int grid_x;
    int grid_y;
    int found_wall = 0;
    int beyond_bounds = 0;
    int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
    int ray_vertical = ray_angle == 90 || ray_angle == 270;
    int ray_facing_up = ray_angle > 0 && ray_angle < 180;
    int ray_facing_down = ray_angle > 180 && ray_angle < 360;
    int ray_facing_right = (ray_facing_up && ray_angle < 90) ||
        (ray_facing_down && ray_angle > 270);
    int delta_x;
    int delta_y;

    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("ray angle: %i\n", ray_angle);
        printf("horizontal coords x: %i\n", horizontal_coords[0]);
        printf("horizontal coords y: %i\n", horizontal_coords[1]);
        printf("map[0][0] %c\n", map[0][0]);
    } else if (DEBUG) {
        printf("%s\n", "====== START CHECK_HORIZONTAL_INTERSECTIONS =====");
        printf("ray angle: %i\n", ray_angle);
    }

    if (ray_horizontal)
    {
        return 0;
    }
    else if (ray_facing_up)
    {
        current_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - 1;
    }
    else if (ray_facing_down) {
        current_y = floor(player->y_coord / CUBE_LENGTH)
            * CUBE_LENGTH + CUBE_LENGTH;
    } else {
        printf("warning! ray_angle %i is over 360 degrees, did not handle the case\n", ray_angle);
        return 0;
    }
    current_x = player->x_coord + (player->y_coord - current_y)/tan(ray_angle);

    delta_y = ray_facing_up ? -CUBE_LENGTH : CUBE_LENGTH;
    if (ray_vertical) {
        delta_x = 0;
    } else if (ray_facing_right) {
        delta_x = CUBE_LENGTH/tan(60);
    } else {
        delta_x = -(CUBE_LENGTH/tan(60));
    }

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
                printf("beyond bounds, breaking out of loop\n");
                break;
            }
             grid_x = current_x / CUBE_LENGTH;
             grid_y = current_y / CUBE_LENGTH;
             printf("grid_x: %i, grid_y: %i\n", grid_x, grid_y);
             printf("map[grid_y][grid_x]: %c\n", map[grid_y][grid_x]);
            if (map[grid_y][grid_x] == 'X') {
                found_wall = 1;
                horizontal_coords[0] = current_x;
                horizontal_coords[1] = current_y;
            } else {
                printf("did not find wall, repeating loop \n");
            }
            current_x += delta_x;
            current_y += delta_y;
         }

    printf("====== END CHECK_HORIZONTAL_INTERSECTIONS; found_wall =%i, x %i, y %i ===== \n",
    found_wall, horizontal_coords[0], horizontal_coords[1]);
    return found_wall;
}
