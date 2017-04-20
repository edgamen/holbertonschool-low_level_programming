#include "maze.h"

/* Return pointer to player instance */
Player_POV *init_player(void)
{
    static Player_POV player;

    player.x_coord = DEFAULT_START_POS_X;
    player.y_coord = DEFAULT_START_POS_Y;
    player.angle = DEFAULT_START_ANGLE;

    return &player;
}
