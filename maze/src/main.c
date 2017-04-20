#include "maze.h"
#include <stdio.h>

/* Return 0 on success, 1 on failure */
int main(void)
{
  SDL_Instance instance;
  int sky_position[4] = SKY_POS;
  int sky_color[4] = SKY_COLOR;
  int floor_position[4] = FLOOR_POS;
  int floor_color[4] = FLOOR_COLOR;
  char *map;

  /* Initialize player and map data */
  map = init_map();
  /* Now test the map we made -- each char is 64 units wide, so player will be
  in one of these... sigh */
  /* Based on initial player location and map data,
     calculate the wall height of ea. column-- store it in an array? */

  if (init_instance(&instance) != 0)
    {
      return (1);
    }

  while (poll_events() == 0)
    {
      SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
      SDL_RenderClear(instance.renderer);
      draw_maze(instance);
      draw_rectangle(instance, sky_position, sky_color);
      draw_rectangle(instance, floor_position, floor_color);
      SDL_RenderPresent(instance.renderer);
    }

  clean_up_SDL(&instance);

  return (0);
}
