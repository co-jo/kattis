#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <math.h>

#define MAX 5

using namespace std;

bool reachable(pair<double, double> wall, pair<int, int> crane, int reach) {
 double hypo = hypot(
    fabs(double(crane.first) - wall.first),
    fabs(double(crane.second)- wall.second)
 );

 if (hypo <= double(reach)) {
  return true;
 } else {
  return false;
 }
}

int main() {
  int length, width, num, radius;
  cin >> length >> width >> num >> radius;

  vector<pair<double, double>> walls;
  // Calculate 4 wall positions
  walls.push_back(make_pair(double(length)/2.0, 0.0));
  walls.push_back(make_pair(double(-length)/2.0, 0.0));
  walls.push_back(make_pair(0.0, double(width)/2.0));
  walls.push_back(make_pair(0.0, double(-width)/2.0));

  //multimap<int, int> cranes;
  vector<pair<int, int>> cranes;
  for (int i = 0; i < num; i++) {
    int x, y, count, id, shift;
    x = y = count = id = shift = 0;

    cin >> x >> y;
    bool can_reach = false;
    pair<int, int> crane = make_pair(x, y);
    for (auto wall : walls) {
      if (reachable(wall, crane, radius)) {
        can_reach = true;
        id += 1 << shift;
        count++;
      }
      shift++;
    }
    // Only push the crane if it reaches at least one wall.
    if (can_reach) {
      pair<int, int> crane = make_pair(count, id);
      cranes.push_back(crane);
    }
  }

  int minc = MAX;
  // Each level represents some |d| subset.
  for (int i = 0; i < cranes.size(); i++) {
    int id = cranes[i].second;
    // Absolute min.
    if (id == 15) { minc = 1; break; }
    for (int j = i + 1; j < cranes.size(); j++) {
      int jid = id | cranes[j].second;
      if (jid == 15) minc = min(minc, 2);
      for (int k = j + 1; k < cranes.size(); k++) {
        int kid = jid | cranes[k].second;
        if (kid == 15) minc = min(minc, 3);
        for (int l = k + 1; l < cranes.size(); l++) {
          int lid = kid | cranes[l].second;
          if (lid == 15) minc = min(minc, 4);
        }
      }
    }
  }

  if (minc < MAX && minc > 0) cout << minc << endl;
  else {
    cout << "Impossible" << endl;
  }

  return 0;
}
