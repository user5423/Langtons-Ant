#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"

int main(int argv, char *argc[]) {
   if (argv == 1){
      return binary_langtons_ant();
   } else if (argv == 2){
      //TODO: Do I need to validate input?
      return generalized_langtons_ant(argc[1]);
   } else {
      return -1;
   }

}

int generalized_langtons_ant(char *ruleset){
   struct ant ant;
   // First we need to define the ruleset
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
