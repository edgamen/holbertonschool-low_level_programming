#include "maze.h"

/**
 * cast_ray - Cast ray to determine attributes of column to draw
 * @ray_angle: absolute angle of ray being cast (degrees)
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 * @line: line to draw
 */
void cast_ray(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH],
	Line *line)
{
	float raw_distance;
	float skewed_distance;
	float col_length;
	float relative_angle;
	char horizontal_or_vert = '\0';

	raw_distance = find_distance(ray_angle, player, map, &horizontal_or_vert);
	if (raw_distance == -1)
	{
		line->start = 0;
		line->end = 0;
		return;
	}
	relative_angle = ray_angle - player->angle;
	skewed_distance = raw_distance * cos(DEG_TO_RADIAN * relative_angle);
	col_length = (CUBE_LENGTH / skewed_distance) * PROJECTION_PLANE_DISTANCE;
	line->start = WINDOW_HEIGHT / 2 - col_length / 2;
	line->end = line->start + col_length;
	line->direction = find_direction(ray_angle, horizontal_or_vert);
}
