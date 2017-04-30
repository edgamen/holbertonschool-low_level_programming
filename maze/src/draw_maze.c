#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH])
{
    int i;
    int ray_angle;
    int *coords;

    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    ray_angle = player->angle - FIELD_OF_VISION / 2;
    for (i = 0; i < WINDOW_WIDTH; i++) {
        coords = cast_ray(ray_angle, player, map);
        SDL_RenderDrawLine(instance.renderer, i, coords[0], i, coords[1]);
        ray_angle += FIELD_OF_VISION / WINDOW_WIDTH;
        /* while testing, let's break out of loop */
        if (TESTING) {
            break;
        }
    }
}

/* to cast a ray, we need player angle, location, map */
