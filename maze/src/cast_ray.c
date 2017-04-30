#include "maze.h"
#include <stdlib.h>

/* Draw the maze */
float *cast_ray(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
    static float coords[2];
    float raw_distance;
    float skewed_distance;
    float col_length;

    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player x: %f\n", player->x_coord);
        printf("Player y: %f\n", player->y_coord);
        printf("Player angle: %f\n", player->angle);
        printf("char: %c\n", map[0][0]);
        printf("ray angle: %f\n", ray_angle);
    } else if (DEBUG) {
        printf("%s\n", "====== CAST_RAY START =====");
    }

    raw_distance = find_distance(ray_angle, player, map);
    if (raw_distance == -1) {
        printf("find_distance reports no wall\n");
        coords[0] = 0;
        coords[1] = 0;
        return coords;
    }
    skewed_distance = player->angle - ray_angle;
    printf("distance: %f, skewed_distance: %f\n", raw_distance, skewed_distance);
    col_length = skewed_distance * SCALE_VALUE;
    printf("wall slice (column) length: %f\n", col_length);
    coords[0] = WINDOW_HEIGHT / 2 - col_length / 2;
    coords[1] = coords[0] + col_length;

    printf("%s\n", "====== CAST_RAY END =====");
    return coords;
}
