#include "maze.h"

/* Draw the maze */
void draw_maze(SDL_Instance instance)
{
    int i;
    int *coords;

    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (i = 0; i < WINDOW_WIDTH; i++) {
        coords = cast_ray(i);
        SDL_RenderDrawLine(instance.renderer, i, coords[0], i, coords[1]);
    }
}
