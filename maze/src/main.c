#include "maze.h"
#include <stdio.h>

/* Return 0 on success, 1 on failure */
int main(void)
{
  SDL_Instance instance;
  Player_POV *player;
  char (*map)[MAP_WIDTH];

  /* Initialize player and map data */
  map = init_map();
  player = init_player();
  /* Debugging: */
  if (DEBUG_DEFAULT) {
      printf("Player x: %f\n", player->x_coord);
      printf("Player y: %f\n", player->y_coord);
      printf("Player angle: %f\n", player->angle);
  }

  if (init_instance(&instance) != 0)
    {
      return (1);
    }

    while (poll_events(player) == 0)
    {
      SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
      SDL_RenderClear(instance.renderer);
      draw_scene(instance, player, map);
      SDL_RenderPresent(instance.renderer);
      /* remove when finished testing */
      if (TESTING) {
          break;
      }
    }

  clean_up_SDL(&instance);

  return (0);
}
