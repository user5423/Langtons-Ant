#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

extern int max_x;
extern int max_y;

typedef enum colour cell;

cell cell_under_ant(struct ant ant);
void start_visualisation(struct ant *ant);
void visualise_and_advance();
bool not_quit();
cell cell_at_fct(int y, int x);
void end_visualisation();

// generalized options
void generalize_visualise_and_advance(struct ant *ant, const char *states, int states_length);
void generalize_start_visualization(struct ant *ant);
void ant_setup(struct ant *ant);
void screen_start();
// char *create_colors(); // Safe implementation using visible 7bit-ascii chars only
#endif
