#include "maze.h"
#include <stdlib.h>

/* Draw the maze */
void cast_ray(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH], Line *line)
{
    float raw_distance;
    float skewed_distance;
    float col_length;
    float relative_angle;
    char horizontal_or_vert = '\0';

    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player angle: %f\n", player->angle);
        printf("char: %c\n", map[0][0]);
        printf("ray angle: %f\n", ray_angle);
    } else if (DEBUG) {
        printf("%s\n", "====== CAST_RAY START =====");
        printf("Player x: %f\n", player->x_coord);
        printf("Player y: %f\n", player->y_coord);
        printf("map width bound: %f\n", MAP_WIDTH_BOUND);
        printf("map height bound: %f\n", MAP_HEIGHT_BOUND);
    }

    raw_distance = find_distance(ray_angle, player, map, &horizontal_or_vert);
    if (raw_distance == -1) {
        printf("find_distance reports no wall\n");
        line->start = 0;
        line->end = 0;
        return;
    }
    relative_angle = ray_angle - player->angle;
    skewed_distance = raw_distance * cos(DEG_TO_RADIAN * relative_angle);
    printf("distance: %f, skewed_distance: %f\n", raw_distance, skewed_distance);
    col_length = (CUBE_LENGTH / skewed_distance) * PROJECTION_PLANE_DISTANCE;
    printf("wall slice (column) length: %f\n", col_length);
    line->start = WINDOW_HEIGHT / 2 - col_length / 2;
    line->end = line->start + col_length;
    line->direction = find_direction(ray_angle, horizontal_or_vert);

    printf("%s\n", "====== CAST_RAY END =====");
    return;
}
