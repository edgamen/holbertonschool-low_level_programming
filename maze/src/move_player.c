#include "maze.h"

/**
 * move_player - Move player in the correct direction (angle)
 * @player: pointer to player instance
 * @angle: absolute angle of direction to move player in (degrees)
 */
void move_player(Player_POV *player, float angle)
{
	player->y_coord -= sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
	player->x_coord += cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
}
