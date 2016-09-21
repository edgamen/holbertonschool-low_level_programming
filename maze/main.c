#include "maze.h"
#include <stdio.h>

/* Return 0 on success, 1 on failure */
int main(void)
{
  SDL_Instance instance;

  if (init_instance(&instance) != 0)
    {
      return (1);
    }

  while (1)
    {
      SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
      SDL_RenderClear(instance.renderer);
      draw_maze(instance);
      SDL_RenderPresent(instance.renderer);
    }

  return (0);
}

void draw_maze(SDL_Instance instance)
{
  SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}
