#include "maze.h"

/* Initialize a new instance of SDL
   Return 0 on success, 1 on fail
 */
int init_instance(SDL_Instance *instance)
{
  /* Initialize SDl */
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      fprintf( stderr, "Unable to initialize SDL: %s\n", SDL_GetError() );
      return (1);
    }

  /* Create a new SDL_Window instance */
  instance->window = SDL_CreateWindow( WINDOW_TITLE, \
				       SDL_WINDOWPOS_CENTERED,	\
				       SDL_WINDOWPOS_CENTERED,	\
				       WINDOW_WIDTH,		\
				       WINDOW_HEIGHT,		\
				       0 );
  if (instance->window == NULL)
    {
      fprintf( stderr, "Unable to create window: %s\n", SDL_GetError() );
      SDL_Quit();
      return (1);
    }

  /* Create a new SDL_Renderer instance linked to SDL_Window */
  instance->renderer = SDL_CreateRenderer( instance->window, -1, \
					SDL_RENDERER_ACCELERATED | \
					 SDL_RENDERER_PRESENTVSYNC );
  if (instance->renderer == NULL)
    {
      fprintf( stderr, "Unable to create renderer: %s\n", SDL_GetError() );
      SDL_DestroyWindow(instance->window);
      SDL_Quit();
      return (1);
    }
  
  /* Debugging: */
  printf("Addr of instance: %p\n", (void *)instance);
  printf("Addr of window: %p\n", (void *)instance->window);
  printf("Addr of renderer: %p\n", (void *)instance->renderer);
  
  return (0);
}
