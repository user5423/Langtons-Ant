// #include <ncurses.h>
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "visualiser.h"

#define cell_at(y,x) cells[(y)*max_x + (x)] // Modify for correct boundary behaviour
// these calls should not handle unsanitised values (this isn't good design) -- it is sanitised before any calls are made using normalize_index() macro
#define gcell_at(y,x) gcells[(y)*max_x + (x)] 
#define cell_under_ant cell_at(ant->y, ant->x)
#define gcell_under_ant gcell_at(ant->y, ant->x)

cell *cells;
int *gcells;

int max_x;
int max_y;

void screen_setup(){
   setlocale(LC_ALL, "");
   initscr(); // Initializes the library and returns a window object
   curs_set(FALSE); // Sets the cursor to invisible
   max_x = getmaxx(stdscr); // gets the max width (w) of the window
   max_y = getmaxy(stdscr); // gets the max height (y) of the window
}

void ant_setup(struct ant *ant){
   ant->x = max_x/2; // Sets the ants struct instance default values
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void start_visualisation(struct ant *ant) {
   screen_setup();
   ant_setup(ant);
   cells = calloc(max_y*max_x, sizeof(cell)); // creates a cells memory block
}

// Since we cannot make significant changes the original datastructures, we are forced to create functions that generalize using different structures
void generalize_start_visualization(struct ant *ant){
   screen_setup();
   ant_setup(ant);
   gcells = calloc(max_y*max_x, sizeof(int)); // creates a cells memory block
}

void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++){
         for (int x=0; x<max_x; x++){
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                  ? "█"
                    : " " 
            );
         }
      }
      refresh();

      /* Advance to next step */
      apply_rule(&cell_under_ant, ant);
      move_forward(ant);
}

void generalize_visualise_and_advance(struct ant* ant, const char *states, int states_length){
   // BUG: 4UL / large characters are fucking up

   //Draws cells and ants
   for (int y=0; y<max_y; y++){
      for (int x=0; x<max_x; x++){
         if (ant_is_at(y,x)){
            mvprintw(y, x, direction_to_s(ant->direction));
         } else if (gcell_at(y,x)) {
            // We are using utf-8 chars and starting at +32 "to avoid invisible character start"
            wchar_t c = (wchar_t) gcell_at(y,x) + 32;
            //FIXED: Large pixel length chars such as mandarin no longer caussing weird visualisation issues due to v
            mvaddnwstr(y, x, &c, 1);
         } else {
            mvprintw(y, x, " ");
         }
      }
   }
   refresh();
   apply_generalized_rule(&gcell_under_ant, ant, states, states_length);
   move_forward(ant);   
}

// Safe 7-bit ascii (visibile only) implementation for generalized
// char *create_colors(){
//    return " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%%&'()*+,-./:;<=>?@[\\]^]^_|}~";
// }

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

wchar_t getNextChar(){
   // we need to know how many previous chars have been skipped from this current index
   // -- we need to skip < > up down
   // -- we need to skip larger length chars
   ;
}

void end_visualisation() {
   free(cells);
   endwin();
}



