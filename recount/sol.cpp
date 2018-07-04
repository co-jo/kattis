#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

int main() {
  auto start = std::chrono::high_resolution_clock::now();

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

  auto end = std::chrono::high_resolution_clock::now();
  auto diff = std::chrono::duration<double>(end - start).count();
  std::cout << "Time: " << diff << std::endl;

  return 0;
}
