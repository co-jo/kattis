#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <float.h>

#define DEBUG 0
using namespace std;

class Node {
  public:
    int x, y;
    char id;
    set<double> slopes;
    Node(char id, int x, int y);
};

Node::Node(char id, int x, int y) {
  this->id = id;
  this->x = x;
  this->y = y;
}

int gcd(int a, int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return abs(a);
}


double choose(int n) {
  return (tgamma(n + 1)) / (6 * tgamma(n - 3 + 1));
}

inline bool boundary(int n, int x, int y) {
  if (x > (n - 1) || x < 0) 
    return false;
  if (y > (n - 1) || y < 0) 
    return false;
  return true;
}
  
int main() {

  string line;
  getline(cin, line);
  int num_lines = stoi(line);
  double result = 0;

  // N <= 100  
  char grid[100][100];
  vector<char> keys;
  map<char, Node> entries;  
  map<char, Node>::iterator it;

  for (int i = 0; i < num_lines; i++) {
    for (int j = 0; j < num_lines; j++) {
      cin >> grid[i][j];
      if (grid[i][j] != '.') {
        char key = grid[i][j];
        Node value = Node(grid[i][j], j, i);
        keys.push_back(key);
        entries.insert(pair<char, Node>(key, value));
      }
    }  
  }

  for (int i = 0; i < keys.size(); i++) {
    for (int j = i + 1; j < keys.size(); j++) {
      // Min 2
      int num_per_line = 2;

      if (DEBUG) line.clear();
      // Line
      Node *origin = &entries.at(keys.at(i));
      Node *end = &entries.at(keys.at(j));
      // Lookup translation values
      int run = (end->x - origin->x);
      int rise = (end->y - origin->y);

      // Transform into smallest jump
      int denom = 1;
      if (run != 0 && rise != 0) {
        denom = gcd(run, rise);
        rise = rise / denom;
        run = run / denom;
      } else {
        if (rise == 0) run = run/abs(run);
        if (run == 0) rise = rise/abs(rise);
      }
      double slope = (run == 0) ? DBL_MAX : ((double)rise/(double)run);
      // Check if Slopes exist between pair (Line already calculated)
      bool found = origin->slopes.find(slope) != origin->slopes.end();

      if (found) continue;

      // Save slopes - Used to check uniqueness
      origin->slopes.insert(slope);
      end->slopes.insert(slope);
      // Debugging..
      if (DEBUG) {
        line += origin->id;
        line += end->id;
      }
      // Next element following same slope
      int ypos = end->y + rise;
      int xpos = end->x + run;

      while (boundary(num_lines, xpos, ypos)) {
        // Check for next possible node in Line
        it = entries.find(grid[ypos][xpos]);
        // Next Step
        ypos += rise;
        xpos += run;
        // If nothing, we haven't reached the boundary and must continue.
        if (it == entries.end()) continue;
        // Success
        num_per_line += 1;
        line += it->second.id;
        it->second.slopes.insert(slope);
      }
      
      if (num_per_line >= 3)  {
        if (DEBUG) {
          cout << line << endl;
          line.clear();
        }
        result += choose(num_per_line);
      }
    }
  } 

  cout << result << endl;

  return 0;
}
