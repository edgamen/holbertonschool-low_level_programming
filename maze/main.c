#include "sdl_instance.h"
#include <stdio.h>

int main(void)
{
  SDL_Instance instance;

  printf("init_instance returned status code %d\n", init_instance(&instance));

  return (0);
}

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
  instance->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (instance->window == NULL)
    {
      fprintf( stderr, "Unable to create window: %s\n", SDL_GetError() );
      /* Clean up SDL -- what needs to happen here */
      return (1);
    }
  
  printf("Addr of instance: %p\n", (void *)instance);
  
  return (0);
}
