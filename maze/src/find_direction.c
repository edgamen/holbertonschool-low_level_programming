#include "maze.h"

/**
 * find_direction - Determine direction of wall ray relative to player
 * @ray_angle: absolute angle of ray being cast (degrees)
 * @horizontal_or_vert: whether closest wall was horizontal or vertical
 *
 * Return: N/S/E/W to indicate direction, or '\0' if undeterminable
 */
char find_direction(float ray_angle, char horizontal_or_vert)
{
	if (horizontal_or_vert == 'H')
	{
		if (ray_angle < 180)
			return ('N');
		else if (ray_angle > 180)
			return ('S');
	}
	else if (horizontal_or_vert == 'V')
	{
		if (ray_angle < 90 || ray_angle > 270)
			return ('E');
		else if (ray_angle > 90 && ray_angle < 270)
			return ('W');
	}
	return ('\0');
}
