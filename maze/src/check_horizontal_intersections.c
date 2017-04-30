#include "maze.h"
#include <stdlib.h>
#include <math.h>

int check_horizontal_intersections(float *horizontal_coords, float ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH])
{
    float start_x;
    float start_y;
    float delta_x;
    float delta_y;
    int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
    int ray_vertical = ray_angle == 90 || ray_angle == 270;
    int ray_facing_up = ray_angle > 0 && ray_angle < 180;
    int ray_facing_down = ray_angle > 180 && ray_angle < 360;
    /* float ray_facing_right = (ray_facing_up && ray_angle < 90) ||
        (ray_facing_down && ray_angle > 270); */
    int found_wall = 0;

    if (HIDE_INFO) {
        printf("Player x: %f\n", player->x_coord);
        printf("Player y: %f\n", player->y_coord);
        printf("Player angle: %f\n", player->angle);
        printf("ray angle: %f\n", ray_angle);
        printf("horizontal coords x: %f\n", horizontal_coords[0]);
        printf("horizontal coords y: %f\n", horizontal_coords[1]);
        printf("map[0][0] %c\n", map[0][0]);
    } else if (DEBUG) {
        printf("%s\n", "====== START CHECK_HORIZONTAL_INTERSECTIONS =====");
        printf("ray angle: %f\n", ray_angle);
    }

    if (ray_horizontal)
    {
        return 0;
    }
    else if (ray_facing_up)
    {
        start_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - 1;
        start_x = player->x_coord + (player->y_coord - start_y)/tan(ray_angle);
    }
    else if (ray_facing_down) {
        start_y = floor(player->y_coord / CUBE_LENGTH)
            * CUBE_LENGTH + CUBE_LENGTH;
        start_x = player->x_coord + (start_y - player->y_coord)/tan(ray_angle);
    } else {
        printf("warning! ray_angle %f is over 360 degrees, did not handle the case\n", ray_angle);
        return 0;
    }

    delta_y = ray_facing_up ? -CUBE_LENGTH : CUBE_LENGTH;
    delta_x = ray_vertical ? 0 : CUBE_LENGTH/tan(ray_angle);
    /* this assumes tangent will not result in appro. -/+ value for agnel
    if (ray_vertical) {
        delta_x = 0;
    } else if (ray_facing_right) {
        delta_x = CUBE_LENGTH/tan(ray_angle);
    } else {
        delta_x = -(CUBE_LENGTH/tan(ray_angle));
    }
    */
    found_wall = check_for_wall(horizontal_coords, start_x, start_y,
        delta_x, delta_y, map);

    printf("====== END CHECK_HORIZONTAL_INTERSECTIONS; found_wall = %i, x %f, y %f ===== \n",
    found_wall, horizontal_coords[0], horizontal_coords[1]);
    return found_wall;
}
