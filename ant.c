#include <string.h>
#include "ant.h"

// Runs langtons_ant on the string "LR" with start ant.direction = "RIGHT"
int binary_langtons_ant(){
   struct ant ant;
   start_visualisation(&ant);
   do {
      visualise_and_advance(&ant);
   } while (not_quit());
   end_visualisation();
   return 0;
}

// Runs langtons_ant on the argument string provided with start ant.direction = "RIGHT"
int generalized_langtons_ant(const char *states){
   // we cannot use enums for cells as these need to be defined at compile time
   struct ant ant;
   int states_length = strlen(states);
   generalize_start_visualization(&ant);
   do {
      generalize_visualise_and_advance(&ant, states, states_length);
   } while (not_quit());
   end_visualisation();
   return 0;
}