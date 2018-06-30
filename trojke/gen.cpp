#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <set>

using namespace std;

int main() {
  srand ((unsigned int)time(NULL));

  int gen = rand() % 30 + 3;
  char symbols[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
  };
  char grid[100][100] = {'.'};
  int index = 0;

  cout << gen << endl;
  for (int i = 0; i < gen; i++) {
    for (int j = 0; j < gen; j++) {
      int add = rand() % gen;
      if (add == 3 && index < 25) {
        grid[i][j] = symbols[index];
        index++;
      } else {
        grid[i][j] = '.';
      } 
      cout << grid[i][j];
    }
    cout << endl;
  }
 
  return 0;
}
