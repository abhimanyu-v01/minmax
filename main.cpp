#include "game.h"
#include <cmath>
#include <iostream>
#include <ostream>

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

  int cplayer = 1, bot = 0;
  int move;
  int iteration = 0;
  draw();

  // Main Game Loop
  while (iteration < (row * column)) {
    cplayer = abs(cplayer - bot);
    if (cplayer) {
      player(move, iteration % 2, (iteration % 2) + 1, iteration);
    } else {
      // bot logic here
    }
    draw();

    if (wincheck()) {
      break;
    }
    iteration++;
  }

  std::cout << ele[iteration % 2] << " Wins" << std::endl;
  return 0;
}
