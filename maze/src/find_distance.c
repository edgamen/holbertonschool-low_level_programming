#include "maze.h"
#include <stdlib.h>

int calculate_distance(Player_POV *player, int *coords) {
    int x_diff;
    int y_diff;


    x_diff = (player->x_coord - coords[0]);
    y_diff = (player->y_coord - coords[1]);
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

/* Draw the maze */
int find_distance(int ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int found_horizontal_coords;
    int horizontal_coords[2] = {5, 4};
    int found_vertical_coords;
    int vertical_coords[2] = {2, 3};

    int distance_to_horizontal_coord;
    int distance_to_vertical_coord;

    /* Debugging: */
    if (HIDE_INFO) {
        printf("Player x: %i\n", player->x_coord);
        printf("Player y: %i\n", player->y_coord);
        printf("Player angle: %i\n", player->angle);
        printf("char: %c\n", map[0][0]);
        printf("ray angle: %i\n", ray_angle);
    } else if (DEBUG) {
        printf("%s\n", "====== FIND_DISTANCE START =====");
    }

    /* do mathy things and calculate length of line to draw) */
    found_horizontal_coords = check_horizontal_intersections(horizontal_coords,
        ray_angle, player, map);
    found_vertical_coords = check_vertical_intersections(vertical_coords,
        ray_angle, player, map);

    if (DEBUG) {
        if (!found_horizontal_coords) {
            printf("%s\n", "NO HORIZONTAL COORDS");
        } else {
            printf("horizontal_coords x: %i\n", horizontal_coords[0]);
            printf("horizontal_coords y: %i\n", horizontal_coords[1]);
        }
        if (!found_vertical_coords) {
            printf("%s\n", "NO VERTICAL COORDS");
        } else {
            printf("vertical_coords x: %i\n", vertical_coords[0]);
            printf("vertical_coords y: %i\n", vertical_coords[1]);
        }
    }

    if (!found_horizontal_coords && !found_vertical_coords) {
        return (-1); /* not no distance, but no wall for ray */
    } else if (found_horizontal_coords && !found_vertical_coords) {
        return calculate_distance(player, horizontal_coords);
    } else if (!found_horizontal_coords && !found_vertical_coords) {
        return calculate_distance(player, vertical_coords);
    }
    distance_to_horizontal_coord =
        calculate_distance(player, horizontal_coords);
    distance_to_vertical_coord = calculate_distance(player, vertical_coords);
    printf("distance to horizontal coord: %i\n", distance_to_horizontal_coord);
    printf("distance to vertical coord: %i\n", distance_to_vertical_coord);
    if (distance_to_horizontal_coord < distance_to_vertical_coord) {
       return distance_to_horizontal_coord;
    } else {
        return distance_to_vertical_coord;
    }

    printf("%s\n", "====== CAST_RAY END =====");
}
