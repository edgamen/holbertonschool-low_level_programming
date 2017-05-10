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
    int found_wall = 0;

    if (DEBUG) {
        printf("%s\n", "====== START CHECK_HORIZONTAL_INTERSECTIONS =====");
        printf("ray angle: %f\n", ray_angle);
    }

    if (ray_horizontal)
    {
        return 0;
    }
    else if (ray_facing_up)
    {
        start_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - .00001;
        start_x = player->x_coord +
            (player->y_coord - start_y)/tan(DEG_TO_RADIAN * ray_angle);
    }
    else if (ray_facing_down) {
        start_y = floor(player->y_coord / CUBE_LENGTH)
            * CUBE_LENGTH + CUBE_LENGTH;
        start_x = player->x_coord +
            (start_y - player->y_coord)/tan(DEG_TO_RADIAN * ray_angle);
    } else {
        printf("warning! ray_angle %f is over 360 degrees, did not handle the case\n", ray_angle);
        return 0;
    }

    delta_y = ray_facing_up ? -CUBE_LENGTH : CUBE_LENGTH;
    delta_x = ray_vertical ? 0 : CUBE_LENGTH/tan(DEG_TO_RADIAN * ray_angle);

    found_wall = check_for_wall(horizontal_coords, start_x, start_y,
        delta_x, delta_y, map);

    printf("====== END CHECK_HORIZONTAL_INTERSECTIONS; found_wall = %i, x %f, y %f ===== \n",
    found_wall, horizontal_coords[0], horizontal_coords[1]);
    return found_wall;
}
