#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"

int main() {
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
