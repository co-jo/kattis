#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;
bitset<36> empty = 0b0;
vector<bitset<36>> choices;
vector<bitset<36>> picked;

int backtrack(int size, int target) {
  if (size < target) {
    for (int i = 0; i < choices.size(); i++) {
      if (choices[i] == empty) continue;
      picked.push_back(choices[i]);
      choices[i] = empty;
      int result = backtrack(size + 1, target);
      choices[i] = picked.back();
      picked.pop_back();
      if (result) return result;
    }
  } else {
    bitset<36> base = bitset<36>().set();
    for (int i = 0; i < picked.size(); i++) base &= picked[i];
    if (base.count() >= target) return target;
  }
  return 0;
}

int solution() {
  int pairs;
  cin >> pairs;
  map<int, bitset<36>> shapes;
  map<int, bitset<36>> styles;
  array<map<int, int>, 2> degrees;

  for (int j = 0; j < pairs; j++) {
    int style, shape;
    cin >> shape >> style;
    styles[shape].set(style - 1);
    shapes[style].set(shape - 1);
    degrees[0][style]++;
    degrees[1][shape]++;
  }

  int max = 0;
  bool flag = true;
  for (auto it = degrees[0].begin(); it != degrees[0].end(); it++){
    max = (max < it->second) ? it->second : max;
  }

  for (auto it = degrees[1].begin(); it != degrees[1].end(); it++){
    max = (max < it->second) ? it->second : max;
    if(max < it->second) {
      max = it->second;
      flag = false;
    }
  }

  map<int, bitset<36>> outgoing = (flag) ? styles : shapes;
  map<int, bitset<36>> incoming = (flag) ? shapes : styles;

  for (int j = max; j > 0; j--) {
    vector<bitset<36>> sample;
    for (auto it = outgoing.begin(); it != outgoing.end(); it++) {
      bitset<36> neighbours = it->second;

      int count = 0;
      if (neighbours.count() >= j) {
        for (int k = 0; k < 36; k++) {
          if (neighbours[k]) {
            int neighbour = incoming[k + 1].count();
            if (neighbour >= j) count++;
          }
        }

        if (count >= j) sample.push_back(neighbours);

        if (sample.size() >= j) {
          choices = sample;
          int res = backtrack(0, j);
          if (res) return res;
        }
      }
    }
  }

  return 0;
}

int main() {
  int num;
  cin >> num;

  for (int i = 0; i < num; i++) {
    int res = solution();
    cout << res << endl;
  }

  return 0;
}
