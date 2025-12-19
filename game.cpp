#include "game.h"
#include <iostream>

// Define the constants
const int row = 3;
const int column = 3;
char grid[row][column];
int og_grid[row][column];
char ele[] = {'X', 'O'};
int moves[row * column] = {};

void draw() {
  std::cout << "\033[2J\033[H";
  for (int i = 0; i < row; i++) {
    std::cout << " ___ ___ ___      ___ ___ ___" << std::endl;
    std::cout << "| ";
    for (int j = 0; j < column; j++) {
      std::cout << grid[i][j] << " | ";
    }
    std::cout << "   | ";
    for (int k = 0; k < column; k++) {
      std::cout << og_grid[i][k] << " | ";
    }
    std::cout << "";
    std::cout << std::endl;
  }
  std::cout << " ___ ___ ___      ___ ___ ___\n\n" << std::endl;
}

void player(int &move, int choice, int turn, int &iteration) {
  std::cout << ele[choice] << "'s Turn: ";
  std::cin >> move;
  move -= 1;
  if ((move >= 0 && move < (row * column)) &&
      grid[move / column][move % column] == ' ') {
    grid[move / column][move % column] = ele[choice];
    moves[iteration] = move;
  } else {
    iteration--;
  }
}

int wincheck() {
  // row wincheck
  for (int i = 0; i < row; i++) {
    if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] &&
        grid[i][1] == grid[i][2])
      return 1;
  }
  // column wincheck
  for (int i = 0; i < column; i++) {
    if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] &&
        grid[1][i] == grid[2][i])
      return 1;
  }
  // diagonal wincheck
  if (grid[1][1] != ' ' &&
      (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) |
          (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) {
    return 1;
  }

  return 0;
}
