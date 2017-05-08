#ifndef MAZE_HEADERS
#define MAZE_HEADERS

#include <SDL2/SDL.h>
#include <math.h>

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

typedef struct Player_POV
{
  float x_coord;
  float y_coord;
  float angle;
} Player_POV;

typedef struct Coord
{
  float x;
  float y;
} Coord;

/* Macros: */
#define TESTING 0
#define HIDE_INFO 0
#define DEBUG 1

#define WINDOW_TITLE "Maze"
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

#define CUBE_LENGTH 64.0 /* units */
#define MAP_WIDTH 8
#define MAP_HEIGHT 9
#define MAP_WIDTH_BOUND MAP_WIDTH * CUBE_LENGTH
#define MAP_HEIGHT_BOUND MAP_HEIGHT * CUBE_LENGTH

#define FIELD_OF_VISION 60.0 /* degrees */
#define PLAYER_HEIGHT 32.0 /* units */

#define DEFAULT_START_POS_X 6.5 * CUBE_LENGTH
#define DEFAULT_START_POS_Y 1.5 * CUBE_LENGTH
#define DEFAULT_START_ANGLE 30.0 /* degrees */

/* note: can use SDL_COLOR in the future */
#define SKY_COLOR {102, 194, 255, 0}
#define SKY_POS {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT / 2}
#define FLOOR_COLOR {51, 153, 102, 0}
#define FLOOR_POS {0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2}

#define DEG_TO_RADIAN M_PI / 180.0
#define TAN30 0.57735026919
#define PROJECTION_PLANE_DISTANCE ( WINDOW_WIDTH / 2 ) / TAN30
#define SCALE_VALUE CUBE_LENGTH / PROJECTION_PLANE_DISTANCE

/* Initialize a new instance of SDL */
float init_instance(SDL_Instance *);
/* Initialize map data and return map array */
char (*init_map(void))[MAP_WIDTH];
/* Return pointer to player instance */
Player_POV *init_player(void);
/* Check SDL queue of events for handling */
float poll_events(void);
/* Draw what will be presented on window */
void draw_scene(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Draw the maze */
void draw_maze(SDL_Instance instance, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Draw a rectangle */
void draw_rectangle(SDL_Instance instance, float positions[], float colors[]);
/* Cast ray to determine attributes of column to draw */
float *cast_ray(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH]);
/* Return 0 if no horizontal intersection of ray and wall, else return 1
and set value of horizontal_coords to the closest intersection */
float find_distance(float ray_angle, Player_POV *player, char (*map)[MAP_WIDTH]);
int check_horizontal_intersections(float *horizontal_coords, float ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH]);
/* Return 0 if no vertical intersection of ray and wall, else return 1
and set value of vertical_coords to the closest intersection */
int check_vertical_intersections(float *vertical_coords, float ray_angle,
    Player_POV *player, char (*map)[MAP_WIDTH]);
/* Helper function to check for points along the ray for walls */
int check_for_wall(float *coords, float start_x, float start_y, float delta_x,
    float delta_y, char (*map)[MAP_WIDTH]);
/* Perform clean-up tasks related to SDL before quitting*/
void clean_up_SDL(SDL_Instance *instance);

#endif
