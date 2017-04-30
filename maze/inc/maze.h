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

typedef struct Coord
{
  int x;
  int y;
} Coord;

/* Macros: */
#define TESTING 1
#define HIDE_INFO 0
#define DEBUG 1

#define WINDOW_TITLE "Maze"
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

#define CUBE_LENGTH 64 /* units */
#define MAP_WIDTH 8
#define MAP_HEIGHT 9
#define MAP_WIDTH_BOUND MAP_WIDTH * CUBE_LENGTH
#define MAP_HEIGHT_BOUND MAP_HEIGHT * CUBE_LENGTH

#define FIELD_OF_VISION 60 /* degrees */
#define PLAYER_HEIGHT 32 /* units */

#define DEFAULT_START_POS_X 6.5 * CUBE_LENGTH
#define DEFAULT_START_POS_Y 1.5 * CUBE_LENGTH
#define DEFAULT_START_ANGLE 45 /* degrees */

/* note: can use SDL_COLOR in the future */
#define SKY_COLOR {102, 194, 255, 0}
#define SKY_POS {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2}
#define FLOOR_COLOR {51, 153, 102, 0}
#define FLOOR_POS {0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2}

/* unused
#define TAN30 = 0.57735026919
#define PROJECTION_PLANE_DISTANCE = ( WINDOW_WIDTH / 2 ) / TAN30 -- should be
    277 units
*/

/* Initialize a new instance of SDL */
int init_instance(SDL_Instance *);
/* Initialize map data and return map array */
char (*init_map(void))[MAP_WIDTH];
/* Return pointer to player instance */
Player_POV *init_player(void);
/* Check SDL queue of events for handling */
int poll_events(void);
/* Draw what will be presented on window */
void draw_scene(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Draw a rectangle */
void draw_rectangle(SDL_Instance instance, int positions[], int colors[]);
/* Cast ray to determine attributes of column to draw */
int *cast_ray(int ray_angle, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Return coords of closest horizontal intersection of ray and wall */
int check_horizontal_intersections(int *horizontal_coords, int ray_angle, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Return coords of closest vertical intersection of ray and wall */
int *check_vertical_intersections(int ray_angle, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Perform clean-up tasks related to SDL before quitting*/
void clean_up_SDL(SDL_Instance *instance);

#endif
