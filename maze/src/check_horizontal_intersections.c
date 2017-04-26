#include "maze.h"
#include <stdlib.h>
#include <math.h>

int check_horizontal_intersections(int *horizontal_coords, int ray_angle,
    Player_POV *player, char *map[MAP_WIDTH][MAP_HEIGHT])
{
    int current_x;
    int current_y;
    int grid_x;
    int grid_y;
    int found_wall;

    found_wall = 0;
    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("ray angle: %i\n", ray_angle);
        printf("char: %c\n", map[0]);
        printf("horizontal coords x: %i\n", horizontal_coords[0]);
        printf("horizontal coords y: %i\n", horizontal_coords[1]);
    } else if (DEBUG) {
        printf("%s\n", "====== CHECK_HORIZONTAL_INTERSECTIONS =====");
        printf("ray angle: %i\n", ray_angle);
        printf("map[0][0] %c", map[0][0]);
    }

    /* Q: should we use radians? */
    /* note: don't ask me how this math works exactly */
    if (ray_angle == 0 || ray_angle == 180 || ray_angle == 360)
    {
        return 0;
    }
    else if (ray_angle > 0 && ray_angle < 180)
    {
        current_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - 1;
        horizontal_coords[1] = current_y;
        printf("current y: %i\n", current_y);
    }
    else if (ray_angle > 180 && ray_angle < 360) {
        current_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH + CUBE_LENGTH;
        printf("current y: %i\n", current_y);
    } else {
        printf("warning! ray_angle is over 360 degrees, did not handle the case\n");
        return 0;
    }
    current_x = player->x_coord + (player->y_coord - current_y)/tan(ray_angle);
    printf("current x: %i\n", current_x);

    /* check if there is a wall at the coordinates we've specified */
    while (!found_wall)
         {
             grid_x = current_x / CUBE_LENGTH;
             grid_y = current_y / CUBE_LENGTH;
         }

    /* if ray_angle == 0 or == 180, we return null, null for coords?) */
    return found_wall;
}
