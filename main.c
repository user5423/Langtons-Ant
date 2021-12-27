#include <stdlib.h>
#include <stdio.h>
#include "ant.h"
      
// TODO: Do I need to validate input?
// This includes on a generalized

// TODO: Validate that torous wrap index boundaries are correct
// Is it meant to be +1? or -1? or what?

// TODO: Fix colors (characters)
// How many "colors" do I need to support

// TODO: Ensure we do not change the original structures (ask what level of change is allowed)
// --> Ant->x and Ant-y were originally char, moved to int (TODO: Revert or check if mistake)
// --> Directions enum had the order changed

// TODO: Create tests for generalized functions

// TODO: What should be the starting direction for generalized langtons ant?
// --> Done for generalized_apply_rule

// TODO: Handle shared library creation
// --> Makefile reflected changes
// --> TODO: Find what directory path for .h and .so files to be stored in

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


