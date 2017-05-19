#include "maze.h"

/**
 * draw_scene - Draw what will be shown on window during loop
 * @instance: SDL instance
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 */
void draw_scene(SDL_Instance instance, Player_POV *player, char
	(*map)[MAP_WIDTH])
{
	float sky_position[4] = SKY_POS;
	int sky_color[4] = SKY_COLOR;
	float floor_position[4] = FLOOR_POS;
	int floor_color[4] = FLOOR_COLOR;

	draw_rectangle(instance, sky_position, sky_color);
	draw_rectangle(instance, floor_position, floor_color);
	draw_maze(instance, player, map);
}
