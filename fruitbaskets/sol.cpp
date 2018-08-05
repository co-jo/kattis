#include <string>
#include <iostream>
#include <bitset>
#include <array>
#include <stdint.h>
#include <cmath>

using namespace std;

long long invalid = 0;
void reduce(array<int, 40> &baskets, int index, int num, int sum) {
  if (sum >= 200) return;
  if (sum < 200 && index == num) invalid += sum;
  if (index >= num) return;
  // Include
  reduce(baskets, index + 1, num, sum + baskets[index]);
  // Exclude
  reduce(baskets, index + 1, num, sum);
}

/*
 * Calculate maximum possible total weight;
 * Each fruit on average occurs in half of the subsets,
 * Backtrack on ones that are not incuded.
 */

int main() {
  int num = 0, basket = 0;
  cin >> num;

  array<int, 40> baskets;
  for (int i = 0; i < num; i++) {
    cin >> basket;
    baskets[i] = basket;
  }
 long long max = 0;
  for (int i = 0; i < num; i++) {
    max += baskets[i] * pow(2, num - 1);
  }
  reduce(baskets, 0, num, 0);
  cout << max - res << endl;

  return 0;
}
