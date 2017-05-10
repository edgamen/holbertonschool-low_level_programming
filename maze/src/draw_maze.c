#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int i;
    float ray_angle;
    Line line;

    printf("\n\n\n\n");
    printf("%s\n", "====== DRAW_MAZE START =====");
    ray_angle = player->angle + (float)FIELD_OF_VISION / 2;
    for (i = 0; i < WINDOW_WIDTH; i++) {
        printf("player_angle %f\n", player->angle);
        printf("ray_angle (starts with player angle + FOV / 2) %f\n", ray_angle);
        cast_ray(ray_angle, player, map, &line);
        if (line.direction == 'N') {
            printf("red line, i = %i\n", i);
        }
        if (line.direction == 'W') {
            printf("yellow line, i = %i\n", i);
        }
        set_line_color(instance, line.direction);
        printf("start col %i, end col %i\n", line.start, line.end);
        SDL_RenderDrawLine(instance.renderer, i, line.start, i, line.end);
        ray_angle = ray_angle - (float)FIELD_OF_VISION / WINDOW_WIDTH;
        printf("%s\n", "====== DRAW_MAZE END =====");
        printf("\n\n\n\n");
    }
}

/* to cast a ray, we need player angle, location, map */
