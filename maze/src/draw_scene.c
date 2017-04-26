#include "maze.h"

/* Draw what will be shown on window during loop */
void draw_scene(SDL_Instance instance, Player_POV *player, char *[MAP_WIDTH][MAP_HEIGHT])
{
    int sky_position[4] = SKY_POS;
    int sky_color[4] = SKY_COLOR;
    int floor_position[4] = FLOOR_POS;
    int floor_color[4] = FLOOR_COLOR;

    draw_rectangle(instance, sky_position, sky_color);
    draw_rectangle(instance, floor_position, floor_color);
    draw_maze(instance, player, map);
}
