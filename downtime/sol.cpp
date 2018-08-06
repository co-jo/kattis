#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

int main() {
  int reqs, bandwidth;
  int timestamp = 0, bound = 0;
  cin >> reqs >> bandwidth;

  deque<int> requests;
  for (int i = 0; i < reqs; i++) {
    cin >> timestamp;
    requests.push_back(timestamp);
    int current = requests.front();
    while (!requests.empty() && current <= (timestamp - 1000)) {
      requests.pop_front();
      current = requests.front();
    }
    bound = (bound < requests.size()) ? requests.size() : bound;
  }
  cout << ceil((double)bound/(double)bandwidth) << endl;

  return 0;
}
