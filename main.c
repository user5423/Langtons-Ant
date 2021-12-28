#include <stdlib.h>
#include <stdio.h>
#include "ant.h"
      
// TODO: Do I need to validate input?
// --> This includes on a generalized

// TODO: Test wrap around visually 
// --> odd number of rows might mess this up

// TODO: Ensure we do not change the original structures (ask what level of change is allowed)
// --> Ant->x and Ant-y were originally char, moved to int (TODO: Revert or check if mistake)
// --> Directions enum had the order changed

// TODO: What should be the starting direction for generalized langtons ant?
// --> Done for generalized_apply_rule

int main(int argv, char *argc[]) {
   if (argv == 1){
      return binary_langtons_ant();
   } else if (argv == 2){
      // This support lengths up to 95 -- we can extend this by adding characters from outside ASCII-7
      // --> However, no answer has been provided on the length we need to support
      return generalized_langtons_ant(argc[1]);
   } else {
      printf("Wrong number of arguments -- There are two ways to call this program\n\n");
      printf("\"./main.out\" -- This runs a binary langtons-ant on pre-defined parameters\n");
      printf("\"./main.out (L|R)+\" -- This runs a generalized langtons-ant on the supplied states string\n");
      return 0;
   }
}

// FIXED: The up symbol is swapped with the down symbol incorrectly
// FIXED: Enabled generalized function to use unicode chars
// FIXED: Switched to the old char for binary function
// DONE: Create tests for generalized functions
// DONE: Validate that torous wrap index boundaries are correct
// DONE: Handle shared library creation