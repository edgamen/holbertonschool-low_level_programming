#include "maze.h"

/* Return 1 if any quit event occurs; otherwise return 0 if all events have been checked */
int poll_events(void)
{
  SDL_Event event;
  SDL_KeyboardEvent key;

  /* While the queue is not empty:
     Check if any of the events refer to quitting the program */
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  return (1);
	case SDL_KEYDOWN:
	  key = event.key;
	  /* If 'ESCAPE' is pressed */
	  if (key.keysym.scancode == 0x29)
	    return (1);
	}
    }
  return (0);
}
