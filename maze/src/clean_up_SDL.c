#include "../inc/maze.h"

/* Perform clean-up tasks related to SDL before quitting */
void clean_up_SDL(SDL_Instance *instance)
{
  SDL_DestroyRenderer(instance->renderer);
  SDL_DestroyWindow(instance->window);
  SDL_Quit();

  return;
}
