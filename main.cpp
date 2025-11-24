#include <iostream>

const int row = 3, column = 3;
char grid[row][column];
int og_grid[row][column];
char ele[] = {'X', 'Y'};

void draw() {
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
  std::cout << " ___ ___ ___      ___ ___ ___" << std::endl;
}

void play() {}

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
  std::cout << "Your Choice is :" << ele[choice];

  int turns[row * column];
  for (int y = 0; y < row * column; y++) {
    turns[y] = y % 2;
  }
  std::cout << turns;

  int move;
  int a = 0;
  while (a < (9)) {

    std::cout << "\033[2J\033[H";
    draw();
    std::cout << move / row << " " << move % column << std::endl;
    if (choice == turns[a]) {
      std::cout << "Next Move: ";
      std::cin >> move;
      move -= 1;
      if (move >= 0 && move <= 9) {
        grid[move / row][move % column] = ele[choice];
      }
    }
    a++;
  }
  return 0;
}
