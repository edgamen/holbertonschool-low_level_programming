#include "maze.h"

void move_player(Player_POV *player, float angle) {

    player->y_coord -= sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
    player->x_coord += cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE;
    if (DEBUG_MOVE) {
        printf("Angle of direction: %f\n", angle);
        printf("DEG_TO_RADIAN * angle: %f\n", DEG_TO_RADIAN * angle);
        printf("PLAYER_MOVE %i\n", PLAYER_MOVE);

        printf("cos(DEG_TO_RADIAN * angle): %f\n", cos(DEG_TO_RADIAN * angle));
        printf("raw x: cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE: %f\n\n", cos(DEG_TO_RADIAN * angle) * PLAYER_MOVE);

        printf("sin(DEG_TO_RADIAN * angle): %f\n", sin(DEG_TO_RADIAN * angle));
        printf("raw y: sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE: %f\n\n", sin(DEG_TO_RADIAN * angle) * PLAYER_MOVE);
    }

    if (DEBUG_MOVE) {
        printf("Player moved:\n");
        printf("Player angle: %f\n", player->angle);
        printf("Player x: %f\n", player->x_coord);
        printf("Player y: %f\n\n", player->y_coord);
    }
}
