#ifndef GAME_H
#define GAME_H

// Constants
extern const int row;
extern const int column;
extern char grid[][3];
extern int og_grid[][3];
extern char ele[];
extern int moves[];

// Functions
void draw();
void player(int &move, int choice, int turn, int &iteration);

#endif
