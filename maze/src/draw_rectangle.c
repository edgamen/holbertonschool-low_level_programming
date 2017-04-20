#include "maze.h"

/* Draw a rectangle */
void draw_rectangle(SDL_Instance sdl_instance)
{
    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = WINDOW_WIDTH;
    rectangle.h = WINDOW_HEIGHT / 2;
    SDL_SetRenderDrawColor(sdl_instance.renderer, 0, 90, 245, 255);
    SDL_RenderFillRect(sdl_instance.renderer, &rectangle);
}
