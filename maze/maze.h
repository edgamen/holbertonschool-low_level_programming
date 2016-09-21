#ifndef MAZE_HEADERS
#define MAZE_HEADERS

#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

/* Macros: */
#define WINDOW_TITLE "Maze"
#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 720

/* Initialize a new instance of SDL */
int init_instance(SDL_Instance *);
/* Draw what will be presented on window */
void draw_maze(SDL_Instance instance);
/* Check SDL queue of events for handling */
int poll_events(void);
/* Perform clean-up tasks related to SDL before 
   quitting*/
void clean_up_SDL(SDL_Instance *instance);

#endif
