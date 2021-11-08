#include <stdlib.h>
#include "langton.h"

// Set the ants direction so that it turns left
void turn_left(struct ant *ant) {
	//TODO
}

// Set the ants direction so that it turns right
void turn_right(struct ant *ant) {
	//TODO
}

// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right
void move_forward(struct ant *ant) {
	//TODO
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
	//TODO
}


