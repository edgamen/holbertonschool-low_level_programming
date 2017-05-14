#include "maze.h"

/* Return pointer to player instance */
Player_POV *init_player(void)
{
    static Player_POV player;

    player.x_coord = DEFAULT_START_POS_X;
    player.y_coord = DEFAULT_START_POS_Y;
    player.angle = DEFAULT_START_ANGLE;

    if (DEBUG_MOVE) {
        printf("Player init:\n");
        printf("Player angle: %f\n", player.angle);
        printf("Player x: %f\n", player.x_coord);
        printf("Player y: %f\n\n", player.y_coord);
    }

    return &player;
}
