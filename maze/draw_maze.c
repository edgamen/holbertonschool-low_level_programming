#include "maze.h"

/* Set what will be drawn on window during loop */
void draw_maze(SDL_Instance instance)
{
  SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}
