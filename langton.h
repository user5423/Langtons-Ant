#ifndef langton_h
#define langton_h

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant
{
   char x;
   char y;
   enum direction direction;
};

#define ant_is_at(y,x) ((y) == ant->y && (x) == ant->x)

enum colour { WHITE, BLACK };

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

const char* direction_to_s(enum direction d);

void apply_rule(enum colour *colour, struct ant *ant);

#endif
