#include "maze.h"

/**
 * draw_maze - Draw the maze
 * @instance: SDL instance
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 */
void draw_maze(SDL_Instance instance, Player_POV *player, char
	(*map)[MAP_WIDTH])
{
	int i;
	float ray_angle;
	Line line;

	ray_angle = player->angle + (float)FIELD_OF_VISION / 2;
	for (i = 0; i < WINDOW_WIDTH; i++)
	{
		cast_ray(ray_angle, player, map, &line);
		set_line_color(instance, line.direction);
		SDL_RenderDrawLine(instance.renderer, i, line.start, i, line.end);
		ray_angle = ray_angle - (float)FIELD_OF_VISION / WINDOW_WIDTH;
	}
}
