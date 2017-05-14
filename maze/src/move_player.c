#include "maze.h"

void move_player(Player_POV *player, float angle) {
    player->y_coord -= sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
    player->x_coord += cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
}
