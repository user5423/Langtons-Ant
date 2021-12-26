#include <stdlib.h>
#include "langton.h"
#include <stdio.h>
#include <ncurses.h>

extern int max_y;
extern int max_x;

// Set the ants direction so that it turns left (anti-clockwise)
void turn_left(struct ant *ant) {
   ant->direction = (ant->direction - 1) % DIRECTION_NUMBER;
}

// Set the ants direction so that it turns right (clockwise)
void turn_right(struct ant *ant) {
   ant->direction = (ant->direction + 1) % DIRECTION_NUMBER;
}

// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right
void move_forward(struct ant *ant) {
   int *offset = DIRECTION_OFFSETS[ant->direction];
   ant->y = normalize_index(ant->y + offset[0], max_y);
   ant->x = normalize_index(ant->x + offset[1], max_x);

}

// Do not modify
const char* direction_to_s(enum direction d) {
   return UP   == d ? "^" :
          DOWN == d ? "v" :
          LEFT == d ? "<" :
          /* else */  ">" ;
}

// Call turn_left, or turn_right depending on the color of the current square,
// or in other words: apply the rule:
// * When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
// * When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.
void apply_rule(enum colour *colour, struct ant *ant) {
   // First we need to decide whether to turn_right or turn_left
   (*colour ==  0) ? turn_right(ant) : turn_left(ant);
   // Then we flip the color -- since there's only two options, we can flip it between WHITE and BLACK
   *colour = ! *colour;
   // finally, we move forward
   move_forward(ant);
    
}

void apply_generalized_rule(int *cell, struct ant *ant, const char *states, int state_length){
   // decide whether to turn_left or turn_right
   (states[*cell] == 'L') ? turn_left(ant) : turn_right(ant);
   // update the cell state
   *cell = (*cell + 1) % state_length;
   //we move forward
   move_forward(ant);
}

int binary_langtons_ant(){
   struct ant ant;
   start_visualisation(&ant);
   do {
      visualise_and_advance(&ant);
   } while (not_quit());
   end_visualisation();
   return 0;
}


int generalized_langtons_ant(const char *states){
   // we cannot use enums for cells as these need to be defined at compile time
   struct ant ant;
   char *colors;
   int states_length = strlen(states);
   generalize_start_visualization(&ant);
   create_colors(colors, states_length);
   do {
      generalize_visualise_and_advance(&ant, states, states_length, colors);
   } while (not_quit());
   end_visualisation();
   return 0;
}
