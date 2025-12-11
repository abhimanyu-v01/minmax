#include "game.h"
#include <iostream>

// Define the constants (actually allocate memory)
const int row = 4;
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
  std::cout << "Player " << turn << "'s Turn" << std::endl;
  std::cout << "Next Move: ";
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

void wincheck(int lastplay) {}
