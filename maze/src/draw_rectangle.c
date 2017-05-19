#include "maze.h"

/**
 * draw_rectangle - Draw a rectangle
 * @sdl_instance: SDL instance
 * @positions: array of values for rectangle
 * @colors: array of RGBA values for rectangle color
 */
void draw_rectangle(SDL_Instance sdl_instance, float positions[], int
	colors[])
{
	SDL_Rect rectangle;

	rectangle.x = positions[0];
	rectangle.y = positions[1];
	rectangle.w = positions[2];
	rectangle.h = positions[3];
	SDL_SetRenderDrawColor(sdl_instance.renderer, colors[0], colors[1],
		colors[2], colors[3]);
	SDL_RenderFillRect(sdl_instance.renderer, &rectangle);
}
