#include "maze.h"

/**
 * main - Init values, render and present in loop; clean before exiting
 * Return: exit value
 */
int main(void)
{
	SDL_Instance sdl_instance;
	Player_POV *player;
	char (*map)[MAP_WIDTH];

	map = init_map();
	player = init_player();

	if (init_instance(&sdl_instance) != 0)
	{
		return (1);
	}

	while (poll_events(player) == 0)
	{
		SDL_SetRenderDrawColor(sdl_instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(sdl_instance.renderer);
		draw_scene(sdl_instance, player, map);
		SDL_RenderPresent(sdl_instance.renderer);
	}

	clean_up_SDL(&sdl_instance);

	return (0);
}
