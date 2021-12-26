#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "langton.h"
#include "visualiser.h"
      
// TODO: Do I need to validate input?
// This includes on a generalized

// TODO: Validate that torous wrap index boundaries are correct
// Is it meant to be +1? or -1? or what?

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


