#include "maze.h"

/**
 * cast_ray - Check if there is a wall at the coordinates we've specified
 * @coords: pointer to coords for where wall was found
 * @start_x: starting x point to check for wall
 * @start_y: starting y point to check for wall
 * @delta_x: change in x for next point to check for wall
 * @delta_y: change in y for next point to check for wall
 * @map: pointer to multidim array map
 *
 * Return: 0 if no wall was detected, 1 if a wall was detected
 */
int check_for_wall(float *coords, float start_x, float start_y, float
	delta_x, float delta_y, char (*map)[MAP_WIDTH])
{
	int found_wall = 0;
	int beyond_bounds = 0;
	float x = start_x;
	float y = start_y;
	int grid_x;
	int grid_y;

	while (!found_wall)
	{
		beyond_bounds =
			x > MAP_WIDTH_BOUND ||
			y > MAP_HEIGHT_BOUND ||
			x < 0 || y < 0;
		if (beyond_bounds)
		{
			break;
		}
		 grid_x = x / CUBE_LENGTH;
		 grid_y = y / CUBE_LENGTH;
		if (map[grid_y][grid_x] == 'X')
		{
			found_wall = 1;
			coords[0] = x;
			coords[1] = y;
		}
		x += delta_x;
		y += delta_y;
	}

	return (found_wall);
}
