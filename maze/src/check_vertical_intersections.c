#include "maze.h"

/**
 * check_vertical_intersections - of ray and grid for walls
 * @vertical_coords: pointer to coords for where wall was found
 * @ray_angle: absolute angle of ray being cast (degrees)
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 *
 * Return: 0 if no wall was detected, 1 if a wall was detected
 */
int check_vertical_intersections(float *vertical_coords, float
	ray_angle, Player_POV *player, char (*map)[MAP_WIDTH])
{
	float start_x, start_y, delta_x, delta_y;
	int ray_horizontal = ray_angle == 0 || ray_angle == 180 || ray_angle == 360;
	int ray_vertical = ray_angle == 90 || ray_angle == 270;
	int ray_facing_right = ray_angle < 90 || ray_angle > 270;
	int ray_facing_left = ray_angle > 90 && ray_angle < 270;
	int found_wall = 0;

	if (ray_vertical)
	{
		return (0);
	}
	else if (ray_facing_right)
	{
		start_x = floor(player->x_coord / CUBE_LENGTH) * CUBE_LENGTH
			+ CUBE_LENGTH;
		start_y = player->y_coord + (start_x - player->x_coord) *
			tan(DEG_TO_RADIAN * ray_angle);
	}
	else if (ray_facing_left)
	{
		start_x = floor(player->y_coord / CUBE_LENGTH) * CUBE_LENGTH - .00001;
		start_y = player->y_coord + (player->x_coord - start_x) *
			tan(DEG_TO_RADIAN * ray_angle);
	}
	else
	{
		return (0);
	}
	delta_x = ray_facing_right ? CUBE_LENGTH : -CUBE_LENGTH;
	delta_y = ray_horizontal ? 0 : CUBE_LENGTH * tan(DEG_TO_RADIAN * ray_angle);
	found_wall = check_for_wall(vertical_coords, start_x, start_y,
		delta_x, delta_y, map);
	return (found_wall);
}
