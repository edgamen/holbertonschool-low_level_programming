#ifndef MAZE_HEADERS
#define MAZE_HEADERS

#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

typedef struct Player_POV
{
  int x_coord;
  int y_coord;
  int angle;
} Player_POV;

/* Macros: */
#define WINDOW_TITLE "Maze"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define CUBE_LENGTH 64 /* units */
#define FIELD_OF_VISION 60 /* degrees */
#define PLAYER_HEIGHT 32 /* units */

/* note: can use SDL_COLOR in the future */
#define SKY_COLOR {102, 194, 255, 0}
#define SKY_POS {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2}
#define FLOOR_COLOR {51, 153, 102, 0}
#define FLOOR_POS {0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2}

/* Initialize a new instance of SDL */
int init_instance(SDL_Instance *);
/* Initialize map data and return map array */
char *init_map(void);
/* Check SDL queue of events for handling */
int poll_events(void);
/* Draw what will be presented on window */
void draw_scene(SDL_Instance instance);
/* Draw the maze */
void draw_maze(SDL_Instance instance);
/* Draw a rectangle */
void draw_rectangle(SDL_Instance instance, int positions[], int colors[]);
/* Cast ray to determine attributes of column to draw */
int *cast_ray(int column_i);
/* Perform clean-up tasks related to SDL before quitting*/
void clean_up_SDL(SDL_Instance *instance);

#endif
