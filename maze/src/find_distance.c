#include "maze.h"

/**
 * calculate_distance - Calculate distance of player to coords of wall
 * @player: pointer to player instance
 * @coords: coords of closest wall
 *
 * Return: distance of player to coords of wall
 */
float calculate_distance(Player_POV *player, float *coords)
{
	float x_diff;
	float y_diff;

	x_diff = (player->x_coord - coords[0]);
	y_diff = (player->y_coord - coords[1]);
	return (sqrt((x_diff * x_diff) + (y_diff * y_diff)));
}

/**
 * find_distance - Find distance to closest wall
 * @ray_angle: absolute angle of ray being cast (degrees)
 * @player: pointer to player instance
 * @map: pointer to map multi-dim array
 * @horizontal_or_vert: whether closest wall was horizontal or vertical
 *
 * Return: distance to closest wall from player
 */
float find_distance(float ray_angle, Player_POV *player, char
	(*map)[MAP_WIDTH], char *horizontal_or_vert)
{
	int found_horizontal_coords, found_vertical_coords;
	float distance_to_horizontal_coord, distance_to_vertical_coord;
	float horizontal_coords[2], vertical_coords[2];

	found_horizontal_coords = check_horizontal_intersections(horizontal_coords,
		ray_angle, player, map);
	found_vertical_coords = check_vertical_intersections(vertical_coords,
		ray_angle, player, map);

	if (!found_horizontal_coords && !found_vertical_coords)
	{
		return (-1); /* not no distance, but no wall for ray */
	}
	else if (found_horizontal_coords && !found_vertical_coords)
	{
		*horizontal_or_vert = 'H';
		return (calculate_distance(player, horizontal_coords));
	}
	else if (!found_horizontal_coords && found_vertical_coords)
	{
		*horizontal_or_vert = 'V';
		return (calculate_distance(player, vertical_coords));
	}
	distance_to_horizontal_coord = calculate_distance(player,
		horizontal_coords);
	distance_to_vertical_coord = calculate_distance(player, vertical_coords);
	if (distance_to_horizontal_coord < distance_to_vertical_coord)
	{
		*horizontal_or_vert = 'H';
		return (distance_to_horizontal_coord);
	}
	else
	{
		*horizontal_or_vert = 'V';
		return (distance_to_vertical_coord);
	}
}
