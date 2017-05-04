#include "maze.h"
#include <stdlib.h>

/* Draw the maze */
int *cast_ray(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
    static int coords[2];
    int raw_distance;
    int skewed_distance;
    int col_length;

    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
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
    printf("distance: %i, skewed_distance: %i\n", raw_distance, skewed_distance);
    col_length = skewed_distance * SCALE_VALUE;
    printf("wall slice (column) length: %i\n", col_length);
    coords[0] = WINDOW_HEIGHT / 2 - col_length / 2;
    coords[1] = coords[0] + col_length;

    printf("%s\n", "====== CAST_RAY END =====");
    return coords;
}
