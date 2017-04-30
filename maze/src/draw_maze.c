#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH])
{
    float i;
    float ray_angle;
    float *coords;

    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    printf("player->angle %f\n", player->angle);
    printf("(float)FIELD_OF_VISION / 2 %f\n",(float)FIELD_OF_VISION / 2);
    ray_angle = player->angle - (float)FIELD_OF_VISION / 2;
    for (i = 0; i < 20/* WINDOW_WIDTH */; i++) {
        printf("ray_angle %f\n", ray_angle);
        coords = cast_ray(ray_angle, player, map);
        printf("start col %f, end col %f\n", coords[0], coords[1]);
        SDL_RenderDrawLine(instance.renderer, i, coords[0], i, coords[1]);
        ray_angle = ray_angle + (float)FIELD_OF_VISION / WINDOW_WIDTH;
    }
}

/* to cast a ray, we need player angle, location, map */
