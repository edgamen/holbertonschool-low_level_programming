#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int i;
    float ray_angle;
    Line line;

    if (DEBUG_LVL1) printf("\n\n\n\n");
    if (DEBUG_LVL1) printf("%s\n", "====== DRAW_MAZE START =====");
    ray_angle = player->angle + (float)FIELD_OF_VISION / 2;
    for (i = 0; i < WINDOW_WIDTH; i++) {
        if (DEBUG_LVL1) printf("player_angle %f\n", player->angle);
        if (DEBUG_LVL1) printf("ray_angle (starts with player angle + FOV / 2) %f\n", ray_angle);
        cast_ray(ray_angle, player, map, &line);
        if (line.direction == 'N') {
            if (DEBUG_LVL1) printf("red line, i = %i\n", i);
        }
        if (line.direction == 'W') {
            if (DEBUG_LVL1) printf("yellow line, i = %i\n", i);
        }
        set_line_color(instance, line.direction);
        if (DEBUG_LVL1) printf("start col %i, end col %i\n", line.start, line.end);
        SDL_RenderDrawLine(instance.renderer, i, line.start, i, line.end);
        ray_angle = ray_angle - (float)FIELD_OF_VISION / WINDOW_WIDTH;
        if (DEBUG_LVL1) printf("%s\n", "====== DRAW_MAZE END =====");
        if (DEBUG_LVL1) printf("\n\n\n\n");
    }
}

/* to cast a ray, we need player angle, location, map */
