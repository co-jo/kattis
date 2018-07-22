#include <bitset>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;

  int min = INT_MAX;
  vector<pair<int, int>> ingredients;
  // Fill vector
  for (int i = 0; i < num; i++) {
    int bitter, sour;
    cin >> sour >> bitter;
    ingredients.push_back(make_pair(sour, bitter));
  }

  // Test over each subset.
  for (int i = 0; i < 1<<num; i++) {
    pair<int, int> sum = {1, 0};
    bitset<10> subset(i);
    for (int j = 0; j < num; j++) {
      if (subset[j]) {
        sum.first *= ingredients[j].first;
        sum.second += ingredients[j].second;
        if (abs(sum.first - sum.second) < min) {
          min = abs(sum.first - sum.second);
        }
      }
    }
  }

  cout << min << endl;
  return 0;
}
