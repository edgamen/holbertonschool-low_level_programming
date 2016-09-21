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

  while (poll_events() == 0)
    {
      SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
      SDL_RenderClear(instance.renderer);
      draw_maze(instance);
      SDL_RenderPresent(instance.renderer);
    }

  clean_up_SDL(&instance);
  
  return (0);
}
