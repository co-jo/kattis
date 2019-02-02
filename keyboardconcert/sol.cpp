#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {

  int instruments, notes, note, playable;
  cin >> instruments >> notes;

  vector<vector<bool>> instrument(instruments, vector<bool>(notes + 1, false));
  for (int i = 0; i < instruments; i++) {
    cin >> playable;
    for (int j = 0; j < playable; j++) {
      cin >> note;
      instrument[i][note] = true;
    }
  }

  int swaps = 0;
  bitset<1000> valid = bitset<1000>().set();
  for (int i = 0; i < notes; i++) {
    cin >> note;
    bitset<1000> local = bitset<1000>().set();
    for (int j = 0; j < instruments; j++) {
      if (instrument[j][note] == false) {
        valid[j] = local[j] = false;
      }
    }
    if (valid.count() <= 1000 - instruments) {
      valid = local;
      swaps += 1;
    }
  }

  cout << swaps << endl;

  return 0;
}

