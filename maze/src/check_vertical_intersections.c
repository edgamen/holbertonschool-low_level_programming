#include "maze.h"
#include <stdlib.h>
#include <math.h>

int check_vertical_intersections(float *vertical_coords, float ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH])
{
    float start_x;
    float start_y;
    float delta_x;
    float delta_y;
    int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
    int ray_vertical = ray_angle == 90 || ray_angle == 270;
    int ray_facing_right = ray_angle < 90 || ray_angle > 270;
    int ray_facing_left = ray_angle > 90 && ray_angle < 270;
    int found_wall = 0;

    if (HIDE_INFO) {
        printf("Player x: %f\n", player->x_coord);
        printf("Player y: %f\n", player->y_coord);
        printf("Player angle: %f\n", player->angle);
        printf("ray angle: %f\n", ray_angle);
        printf("horizontal coords x: %f\n", vertical_coords[0]);
        printf("horizontal coords y: %f\n", vertical_coords[1]);
        printf("map[0][0] %c\n", map[0][0]);
    } else if (DEBUG_LVL1) {
        printf("%s\n", "====== START CHECK_VERTICAL_INTERSECTIONS =====");
        printf("ray angle: %f\n", ray_angle);
    }

    if (ray_vertical)
    {
        return 0;
    }
    else if (ray_facing_right)
    {
        start_x = floor(player->x_coord / CUBE_LENGTH) * CUBE_LENGTH
            + CUBE_LENGTH;
        start_y = player->y_coord +
            (start_x - player->x_coord)*tan(DEG_TO_RADIAN *ray_angle);
    }
    else if (ray_facing_left) {
        start_x = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - .00001;;
        start_y = player->y_coord +
            (player->x_coord - start_x)*tan(DEG_TO_RADIAN *ray_angle);
    } else {
        if (DEBUG_LVL1) printf("warning! ray_angle %f is over 360 degrees, did not handle the case\n", ray_angle);
        return 0;
    }

    delta_x = ray_facing_right ? CUBE_LENGTH : -CUBE_LENGTH;
    delta_y = ray_horizontal ? 0 : CUBE_LENGTH*tan(DEG_TO_RADIAN * ray_angle);

    found_wall = check_for_wall(vertical_coords, start_x, start_y,
        delta_x, delta_y, map);

    if (DEBUG_LVL1) printf("====== END CHECK_VERTICAL_INTERSECTIONS; found_wall = %i, x %f, y %f ===== \n",
    found_wall, vertical_coords[0], vertical_coords[1]);
    return found_wall;
}
