#include<string>
#include<iostream>
#include<vector>

#define MAX 5

using namespace std;

// Check if this country's colour is compatible with neighbours.
bool valid(int country, vector<int> &colours, vector<int> &edges) {
  for (int i = 0; i < edges.size(); i++) {
    if (colours[edges[i]] == colours[country]) return false;
  }
  return true;
}

bool backtrack(int countries, int country, int order, vector<vector<int>> &edges, vector<int> &colours) {
  // Completed DFS with no invalidations, must therefore be successful.
  if (country == countries) {
    return true;
  }
  // Avoid whole search space by backtracking.
  for (int i = 1; i <= order; i++) {
    colours[country] = i;
    if (valid(country, colours, edges[country])) {
      if(backtrack(countries, country + 1, order, edges, colours)) {
        return true;
      }
    }
  }
  // Must cleanup on return t avoid future false invalidations.
  colours[country] = 0;
  return false;
}

int main() {
  int num;
  cin >> num;

  for (int i = 0; i < num; i++) {
    int countries, boarders;
    cin >> countries >> boarders;

    vector<vector<int>> edges(countries);
    for (int j = 0; j < boarders; j++) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    int min = MAX;
    // Starting with lower orders; return if answer found.
    for (int order = 1; order <= 4; order++) {
      vector<int> colours(countries, 0);
      bool found = backtrack(countries, 0, order, edges, colours);
      if (found) {
        min = order;
        break;
      }
    }

    if (min < MAX) cout << min << endl;
    else cout << "many" << endl;
  }

  return 0;
}
