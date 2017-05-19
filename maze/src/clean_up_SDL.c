#include "maze.h"

/**
 * clean_up_SDL - Perform clean-up tasks related to SDL before quitting
 * @instance: SDL instance
 */
void clean_up_SDL(SDL_Instance *instance)
{
	SDL_DestroyRenderer(instance->renderer);
	SDL_DestroyWindow(instance->window);
	SDL_Quit();
}
