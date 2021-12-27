#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "langton.h"

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

// Actually move the ant forward based on it's current direction -- should only be called after turn_left or turn_right
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

// Call turn_left, or turn_right depending on the color of the current square -- or in other words: apply the rule:
// * When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
// * When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.
void apply_rule(enum colour *colour, struct ant *ant) {
   (*colour ==  0) ? turn_right(ant) : turn_left(ant); // Decides ant->direction based on the cell's color
   *colour = ! *colour; // Flips the current cell's color 
   move_forward(ant); // Moves ant forward
}

void apply_generalized_rule(int *cell, struct ant *ant, const char *states, int state_length){
   (states[*cell] == 'L') ? turn_left(ant) : turn_right(ant); // Decides ant->direction based on the cell's color
   *cell = (*cell + 1) % state_length; // Updates the cell's state to the next one
   move_forward(ant); // Moves ant forward
}

