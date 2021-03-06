#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> votes;
  std::string line;

  std::string winner;
  int max = 0;
  int count = 0;

  while(getline(std::cin, line)) {
    int val = votes[line]++;
    if (val > max) {
      max = val;
      count = 1;
      winner = line;
    } else if (val == max) {
      count += 1;
    }
  }

  if (count > 1 || max == 1) {
    std::cout << "Runoff!" << std::endl;
  } else {
    std::cout << winner << std::endl;
  }

  return 0;
}
