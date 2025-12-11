#include "game.h"
#include <cmath>
#include <iostream>

int main() {
  std::cout << "\033[2J\033[H";
  int x = 1;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      grid[i][j] = ' ';
      og_grid[i][j] = x;
      x += 1;
    }
  }
  std::cout << "Choose X or O: " << std::endl
            << "1. X\n"
            << "2. O" << "\nChoice: ";
  int num, choice;
  std::cin >> num;
  choice = num - 1;

  int turns[row * column];
  for (int y = choice; y < row * column; y++) {
    turns[y] = y % 2;
  }
  int cplayer = 1, bot = 0;
  int move;
  int iteration = 0;
  draw();

  // Main Game Loop
  while (iteration < (row * column)) {
    cplayer = abs(cplayer - bot);
    if (cplayer) {
      player(move, choice, turns[iteration] + 1, iteration);
    } else {
      // bot logic here
    }
    iteration++;
    choice = iteration % 2;
    draw();
  }
  return 0;
}
