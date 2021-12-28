#ifndef langton_h
#define langton_h

// This is the old enum definition
// enum direction { UP, DOWN, LEFT, RIGHT };
// With the required definitions to lookup for a cleaner operation
// int *direction_clockwise = {3, 2, 0, 1};
// int *direction_anticlockwise = {2, 3, 1, 0};
// int **direction_movements = {{2,3}, {2,3}, {0,1}, {1,0}};

// This is the new enum definition where the numbers are in clockwise-order
enum direction {LEFT, UP, RIGHT, DOWN};

struct ant
{
   //TODO: This was meant to be a char for some reason??? Confirm that is correct
   int x;
   int y;
   enum direction direction;
};

#define ant_is_at(y,x) ((y) == ant->y && (x) == ant->x)
#define gant_is_at(y,x) ((y) == ant->y && (x) == ant->x)

enum colour { WHITE, BLACK };

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

const char* direction_to_s(enum direction d);
void apply_rule(enum colour *colour, struct ant *ant);

// My own definitions
#define DIMENSIONS 2
#define DIRECTION_NUMBER 4
// #define normalize_index(X, UB) ((X >= 0) ? X : UB) % (UB + 1)
#define normalize_index(X, UB) ((X >= 0) ? X : UB-1) % (UB)

// Directions are specified in clockwise order, which allows us to add more movements if we wanted (e.g. LEFTUP, LEFTDOWN, RIGHTUP, RIGHTDOWN for diagonals)
static char *DIRECTIONS[DIRECTION_NUMBER] = {"LEFT", "UP", "RIGHT", "DOWN"};
// Each The indexes of the array above and below correspond to each other
// NOTE: UP is -1 because the origin point is at the top-left instead of bottom-left of cells (and vice versa for DOWN)
static int DIRECTION_OFFSETS[DIRECTION_NUMBER][DIMENSIONS] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
// By allowing the user to change DIMENSION NUMBER, we are able to generalise to different dimensions with minimal code change (the ant struct would need to change)

int binary_langtons_ant();
int generalized_langtons_ant(const char *ruleset);

// generalized declarations
void apply_generalized_rule(int *cell, struct ant *ant, const char *states, int state_length);

#endif
