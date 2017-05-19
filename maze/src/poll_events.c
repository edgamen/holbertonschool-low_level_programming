#include "maze.h"

/**
 * poll_events - Poll keyboard or mouse events for quitting or moving player
 * @player: pointer to player instance
 *
 * Return: Return 1 if any quit event occurs;
 * otherwise return 0 if all events have been checked
 */
int poll_events(Player_POV *player)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	/*
	* While the queue is not empty: Check if any of the events refer to
	* quitting the program or moving player.
	*/
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
			/* If 'ESCAPE' is pressed */
			if (key.keysym.scancode == 0x29)
				return (1);
			if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
				player->angle -= ROTATE_SPEED_FACTOR;
			if (key.keysym.scancode == SDL_SCANCODE_LEFT)
				player->angle += ROTATE_SPEED_FACTOR;
			if (key.keysym.scancode == SDL_SCANCODE_W)
				move_player(player, player->angle);
			if (key.keysym.scancode == SDL_SCANCODE_A)
				move_player(player, player->angle + 90);
			if (key.keysym.scancode == SDL_SCANCODE_S)
				move_player(player, player->angle + 180);
			if (key.keysym.scancode == SDL_SCANCODE_D)
				move_player(player, player->angle - 90);
		}
	}
	return (0);
}
