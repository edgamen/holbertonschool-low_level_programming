#include "maze.h"

void set_line_color(SDL_Instance instance, char direction) {
    if (direction == 'N') {
        SDL_SetRenderDrawColor(instance.renderer, NORTH_COLOR);
    } else if (direction == 'E') {
        SDL_SetRenderDrawColor(instance.renderer, EAST_COLOR);
    } else if (direction == 'S') {
        SDL_SetRenderDrawColor(instance.renderer, SOUTH_COLOR);
    } else if (direction == 'W') {
        SDL_SetRenderDrawColor(instance.renderer, WEST_COLOR);
    } else {
        SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    return;
}
