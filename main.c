#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "langton.h"
#include "visualiser.h"

int main(int argv, char *argc[]) {
   // printf("%d", argv);
   if (argv == 1){
      printf("BINARY\n");
      return binary_langtons_ant();
   } else if (argv == 2){
      //TODO: Do I need to validate input?
      printf("GENERALIZED\n");
      return generalized_langtons_ant(argc[1]);
   } else {
      return -1;
   }

}

int generalized_langtons_ant(const char *states){
   // First we need to define the ruleset
   
   // cell needs to be modified
   // we cannot use enums as these need to be defined at compile time
   // -- however, ruleset is provided at runtime

   // cell can be a struct
   // char cell.state; -- this replaces the enum
   
   // We need datastructures to determine
   // state --> color
   // state --> next_state

   //---------------------

   // we have our rulesetq
   struct ant ant;
   char *colors;
   int states_length = strlen(states);
   generalize_start_visualization(&ant);
   create_colors(colors, states_length);

   do {
      generalize_visualise_and_advance(&ant, states, states_length, colors);
      }
   while (not_quit());

   end_visualisation();
   printf("\nEND OF THE ROAD\n");


   // printf("HERE N");
   // int states_length = strlen(states);
   //TODO: Need to make this scalable with states_length
   // const char **colors = create_colors(states_length); 
   // const char colors[1][2] = {"1"};
   // printf("HERE 3");
   // do { 
   //    generalize_visualise_and_advance(&ant, states, states_length, colors);
   // } while (not_quit());

   // end_visualisation();
   // return 0;

}


int binary_langtons_ant(){
   struct ant ant;
   start_visualisation(&ant);
   
   // Enter loop
   do {
		visualise_and_advance(&ant);
   }
   while (not_quit());

   end_visualisation();

   return 0;

}
