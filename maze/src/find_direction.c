#include "maze.h"

char find_direction(float ray_angle, char horizontal_or_vert) {
    if (DEBUG_DEFAULT) printf("========== FIND_DIRECTION START ==========\n");
    if (DEBUG_DEFAULT) printf("ray_angle %f, horizontal_or_vert %c \n", ray_angle, horizontal_or_vert);

    if (horizontal_or_vert == 'H') {
        if (ray_angle < 180) {
            return 'N';
        } else if (ray_angle > 180) {
            return 'S';
        }
        if (DEBUG_DEFAULT) printf("Error :: Unexpected ray_angle value in find_direction(): %f\n",
        ray_angle);
        if (DEBUG_DEFAULT) printf("Debug :: horizontal_or_vert: %c\n", horizontal_or_vert);
    } else if (horizontal_or_vert == 'V') {
        if (ray_angle < 90 || ray_angle > 270) {
            return 'E';
        } else if (ray_angle > 90 && ray_angle < 270) {
            return 'W';
        }
        if (DEBUG_DEFAULT) printf("Error :: Unexpected ray_angle value in find_direction(): %f\n",
        ray_angle);
        if (DEBUG_DEFAULT) printf("Debug :: horizontal_or_vert: %c\n", horizontal_or_vert);
    }
    if (DEBUG_DEFAULT) printf("Error :: Unexpected horizontal_or_vert value in find_direction: ");
    if (DEBUG_DEFAULT) printf("%c\n", horizontal_or_vert);
    return '\0';
}
