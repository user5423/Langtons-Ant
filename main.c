#include <stdlib.h>
#include <stdio.h>
#include "ant.h"
      
// TODO: Review submission requirements and ensure all of them are correct

int main(int argv, char *argc[]) {
   if (argv == 1){
      // Runs langtons_ant on the string "LR" with start ant.direction = "RIGHT"
      return binary_langtons_ant();
   } else if (argv == 2){
      // Runs langtons_ant on the argument string provided with start ant.direction = "RIGHT"
      // Uses unicode so should theoretically support around 10million states 
      if (validate_input(argc[1]) != -1){
         return generalized_langtons_ant(argc[1]);
      }
   } else {
      // Incorrect number of variables
      printf("Wrong number of arguments -- There are two ways to call this program\n\n");
      printf("\"./main.out\" -- This runs a binary langtons-ant on pre-defined parameters\n");
      printf("\"./main.out (L|R)+\" -- This runs a generalized langtons-ant on the supplied states string\n");
      return 0;
   }
}

// FIXED: The up symbol is swapped with the down symbol incorrectly
// FIXED: Enabled generalized function to use unicode chars
// FIXED: Switched to the old char for binary function
// FIXED: We are allowed to modify ant.x and .y to int type, and we are allowed to reorder enum
// DONE: Create tests for generalized functions
// DONE: Validate that torous wrap index boundaries are correct
// DONE: Handle shared library creation
// FIXED: The generalized langton ant wouldn't display the direction (denoted by the <,>,v,^)
// FIXED: Fix the visual wrap-around issue (Changed the normalize_index macro)
// DONE: Let ant->direction use original default "RIGHT" (what direction are we meant to start?)
