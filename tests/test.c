#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ant.h"

void setup(){
   // Due to how we declare max_x and max_y we need to define them
   // otherwise there may be garbage 0 and 1 values
   extern int max_x, max_y;
   max_x = 50;
   max_y = 50;
}

// Test turn left by performing a full rotation of the ant
void test_turn_left() {
   struct ant ant;
   ant.direction = RIGHT;
   turn_left(&ant);
   assert(ant.direction == UP);
   turn_left(&ant);
   assert(ant.direction == LEFT);
   turn_left(&ant);
   assert(ant.direction == DOWN);
   turn_left(&ant);
   assert(ant.direction == RIGHT);   
}

// Test turn right by performing a full rotation of the ant
void test_turn_right() {
   struct ant ant;
   ant.direction = RIGHT;
   turn_right(&ant);
   assert(ant.direction == DOWN);
   turn_right(&ant);
   assert(ant.direction == LEFT);
   turn_right(&ant);
   assert(ant.direction == UP);
   turn_right(&ant);
   assert(ant.direction == RIGHT);
}

// Test move forward for all 4 directions
void test_move_forward() {
   struct ant ant;
   ant.x = 5;
   ant.y = 5;

   ant.direction = RIGHT;
   move_forward(&ant);
   assert(ant.x == 6 && ant.y == 5);

   ant.direction = LEFT;
   move_forward(&ant);
   assert(ant.x == 5 && ant.y == 5);

   ant.direction = UP;
   move_forward(&ant);
   assert(ant.x == 5 && ant.y == 4);

   ant.direction = DOWN;
   move_forward(&ant);
   assert(ant.x == 5 && ant.y == 5);

   // Additional Test Cases: Boundary Test Cases
   ant.x = 0;
   ant.y = 0;
   // PREV: If there are 50rows, and they start at 0, then the last row will have index 49
   // NOTE: However, this thinking results in a visualisation error when wrapping around
   // FIXED: Therefore returned to 1-based instead of 0 based
   int lastrow = max_y;
   int lastcol = max_x;

   ant.direction = LEFT;
   move_forward(&ant);
   assert(ant.x == lastcol && ant.y == 0);

   ant.direction = RIGHT;
   move_forward(&ant);
   assert(ant.x == 0 && ant.y == 0);

   ant.direction = UP;
   move_forward(&ant);
   assert(ant.x == 0 && ant.y == lastrow);

   ant.direction = DOWN;
   move_forward(&ant);
   assert(ant.x == 0 && ant.y == 0);
   
}


// Test apply rule
void test_apply_rule() {
   struct ant ant;
   cell c;
   ant.x = 5;
   ant.y = 5;
   ant.direction = RIGHT;
   
   c = WHITE;
   apply_rule(&c, &ant);
   assert(ant.direction == DOWN);
   assert(c == BLACK);

   c = BLACK;
   apply_rule(&c, &ant);
   assert(ant.direction == RIGHT);
   assert(c == WHITE);
}

void test_generalized_apply_rule() {
   struct ant ant;
   int c;
   ant.x = 5;
   ant.y = 5;
   ant.direction = RIGHT;

   char *states;
   int states_length;

   // Edge test cases
   c = 0;
   states = "L";
   states_length = strlen(states);
   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == UP);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == LEFT);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == DOWN);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == RIGHT);
   assert(c == 0);

   // Edge test cases
   c = 0;
   states = "R";
   states_length = strlen(states);
   ant.direction = RIGHT;
   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == DOWN);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == LEFT);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == UP);
   assert(c == 0);

   apply_generalized_rule(&c, &ant, states, states_length);
   assert(ant.direction == RIGHT);
   assert(c == 0);


   // Testing whether state loopback works
   states = "RRRRR";
   states_length = strlen(states);
   ant.direction = RIGHT;

   c = states_length - 1;
   apply_generalized_rule(&c, &ant, states, states_length);
   assert(c == 0);

   c = 0;
   apply_generalized_rule(&c, &ant, states, states_length);
   assert(c == 1);
   
}




int main() {
   setup();
	test_turn_right();
	test_turn_left();
	test_move_forward();
	test_apply_rule();
   // Additional tests for generalized langton's ant
   test_generalized_apply_rule();
   printf("-> Tests succesfully ran\n");
}

