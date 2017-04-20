#include "maze.h"

/* Draw a rectangle */
void draw_rectangle(SDL_Instance sdl_instance, int positions[], int colors[])
{
    SDL_Rect rectangle;
    rectangle.x = positions[0];
    rectangle.y = positions[1];
    rectangle.w = positions[2];
    rectangle.h = positions[3];
    SDL_SetRenderDrawColor(sdl_instance.renderer, colors[0], colors[1],
        colors[2], colors[3]);
    SDL_RenderFillRect(sdl_instance.renderer, &rectangle);
}
