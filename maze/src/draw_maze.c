#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int i;
    float ray_angle;
    Line line;

    if (DEBUG_DEFAULT) printf("\n\n\n\n");
    if (DEBUG_DEFAULT) printf("%s\n", "====== DRAW_MAZE START =====");
    ray_angle = player->angle + (float)FIELD_OF_VISION / 2;
    for (i = 0; i < WINDOW_WIDTH; i++) {
        if (DEBUG_DEFAULT) printf("player_angle %f\n", player->angle);
        if (DEBUG_DEFAULT) printf("ray_angle (starts with player angle + FOV / 2) %f\n", ray_angle);
        cast_ray(ray_angle, player, map, &line);
        if (line.direction != 'W') {
            if (DEBUG_WALLBUG) printf("encountered bug, i = %i\n", i);
        }
        set_line_color(instance, line.direction);
        if (DEBUG_DEFAULT) printf("start col %i, end col %i\n", line.start, line.end);
        SDL_RenderDrawLine(instance.renderer, i, line.start, i, line.end);
        ray_angle = ray_angle - (float)FIELD_OF_VISION / WINDOW_WIDTH;
        if (DEBUG_DEFAULT) printf("%s\n", "====== DRAW_MAZE END =====");
        if (DEBUG_DEFAULT) printf("\n\n\n\n");
    }
}

/* to cast a ray, we need player angle, location, map */
