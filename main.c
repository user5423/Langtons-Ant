#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "langton.h"
#include "visualiser.h"
      
// TODO: Do I need to validate input?
// This includes on a generalized

int main(int argv, char *argc[]) {
   if (argv == 1){
      return binary_langtons_ant();
   } else if (argv == 2){
      return generalized_langtons_ant(argc[1]);
   } else {
      printf("Wrong number of arguments -- There are two ways to call this program\n\n");
      printf("\"./main.out\" -- This runs a binary langtons-ant on pre-defined parameters\n");
      printf("\"./main.out (L|R)+\" -- This runs a generalized langtons-ant on the supplied states string\n");
      return -1;
   }

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


int binary_langtons_ant(){
   struct ant ant;
   start_visualisation(&ant);
   do {
      visualise_and_advance(&ant);
   } while (not_quit());
   end_visualisation();
   return 0;
}
