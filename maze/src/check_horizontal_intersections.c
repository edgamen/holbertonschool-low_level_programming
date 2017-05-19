#include "maze.h"

/**
 * check_horizontal_intersections - of ray and grid for walls
 * @horizontal_coords: pointer to coords for where wall was found
 * @ray_angle: absolute angle of ray being cast (degrees)
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 *
 * Return: 0 if no wall was detected, 1 if a wall was detected
 */
int check_horizontal_intersections(float *horizontal_coords, float
	ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
	float start_x, start_y, delta_x, delta_y;
	int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
	int ray_vertical = ray_angle == 90 || ray_angle == 270;
	int ray_facing_up = ray_angle > 0 && ray_angle < 180;
	int ray_facing_down = ray_angle > 180 && ray_angle < 360;
	int found_wall = 0;

	if (ray_horizontal)
	{
		return (0);
	}
	else if (ray_facing_up)
	{
		start_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - .00001;
		start_x = player->x_coord + (player->y_coord - start_y) /
			tan(DEG_TO_RADIAN * ray_angle);
	}
	else if (ray_facing_down)
	{
		start_y = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH
			+ CUBE_LENGTH;
		start_x = player->x_coord + (start_y - player->y_coord) /
			tan(DEG_TO_RADIAN * ray_angle);
	}
	else
	{
		return (0);
	}
	delta_y = ray_facing_up ? -CUBE_LENGTH : CUBE_LENGTH;
	delta_x = ray_vertical ? 0 : CUBE_LENGTH / tan(DEG_TO_RADIAN * ray_angle);
	found_wall = check_for_wall(horizontal_coords, start_x, start_y,
		delta_x, delta_y, map);
	return (found_wall);
}
