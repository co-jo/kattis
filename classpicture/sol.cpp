#include <map>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main() {
  int num;
  while (cin >> num) {
    map<string, unordered_map<string, bool>> persons;
    vector<string> names;
    // Get inputs.
    for (int i = 0; i < num; i++) {
      string name;
      cin >> name;
      names.push_back(name);
      persons[name] = {};
    }

    for (auto it = persons.begin(); it != persons.end(); it++) {
      string key = it->first;
      for (auto itr = persons.begin(); itr != persons.end(); itr++) {
        if (itr->first == key) continue;
        itr->second[key] = true;
      }
    }

    // Remove edges
    int pairs;
    cin >> pairs;
    for (int i = 0; i < pairs; i++) {
      string first, second;
      cin >> first >> second;
      persons[first][second] = false;
      persons[second][first] = false;
    }

    vector<int> nums;
    bool found = false;
    for (int i = 0; i < names.size(); i++)
      nums.push_back(i);

    sort(names.begin(), names.end());
    do {
      int count = 1;
      // Check valid sequence
      for (int i = 0; i < nums.size() - 1; i++) {
        if (persons[names[nums[i]]][names[nums[i + 1]]] == false) break;
        count++;
      }
      if (count == nums.size()) {
        found = true;
        break;
      }
    } while(next_permutation(nums.begin(), nums.end()));

    if (found == false) {
      cout << "You all need therapy." << endl;
    } else {
      for (int i = 0; i < nums.size() - 1; i++)
        cout << names[nums[i]] << ' ';
      cout << names[nums[nums.size() - 1]] << endl;
    }
  }

  return 0;
}
