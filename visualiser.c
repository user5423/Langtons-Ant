#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"

#define cell_at(y,x) cells[(y)*max_x + (x)] // Modify for correct boundary behaviour
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;

int max_x;
int max_y;

void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

   initscr(); // Initializes the library and returns a window object
   curs_set(FALSE); // Sets the cursor to invisible
   max_x = getmaxx(stdscr); // gets the max width (w) of the window
   max_y = getmaxy(stdscr); // gets the max height (y) of the window
   cells = calloc(max_y*max_x, sizeof(cell)); // creates a cells memory block
   ant->x = max_x/2; // Sets the ants struct instance default values
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            // y, x = height, width
            // if ant_is_at(y,x):
            //    direction_to_s(ant->direction)
            // elif cell_at(y,x):
            //    some unprintable char - that looks like a block in Ide
            // else:
            //    " " empty char
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                  //   ? "█"
                  ? "M"
                    : " "
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      apply_rule(&cell_under_ant, ant);
      move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   free(cells);
   endwin();
}

