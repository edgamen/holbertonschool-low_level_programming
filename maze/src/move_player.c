#include "maze.h"

void move_player(Player_POV *player, float angle) {
    int facing_north = player->angle > 0 && player->angle < 180 ? 1 : -1;

    player->y_coord -= sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE * facing_north;
    player->x_coord += cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE * facing_north;
}
