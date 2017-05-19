#include "maze.h"

/**
 * set_line_color - Set color of line to draw
 * @instance: SDL instance
 * @direction: direction of wall (N/S/E/W)
 */
void set_line_color(SDL_Instance instance, char direction)
{
	int north_color[4] = NORTH_COLOR;
	int east_color[4] = EAST_COLOR;
	int south_color[4] = SOUTH_COLOR;
	int west_color[4] = WEST_COLOR;

	if (direction == 'N')
		SDL_SetRenderDrawColor(instance.renderer, north_color[0],
			north_color[1], north_color[2], north_color[3]);
	else if (direction == 'E')
		SDL_SetRenderDrawColor(instance.renderer, east_color[0],
			east_color[1], east_color[2], east_color[3]);
	else if (direction == 'S')
		SDL_SetRenderDrawColor(instance.renderer, south_color[0],
			south_color[1], south_color[2], south_color[3]);
	else if (direction == 'W')
		SDL_SetRenderDrawColor(instance.renderer, west_color[0],
			west_color[1], west_color[2], west_color[3]);
	else
		SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
