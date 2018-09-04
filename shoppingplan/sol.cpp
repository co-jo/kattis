#include <iostream>
#include <cfloat>
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <math.h>
#define DEBUG 0

using namespace std;
int gas;
double minimum = DBL_MAX;
vector<double> results;
tuple<int, int, int, int, bool> home = make_tuple(0, 0, 0, -1, false);

// Cost from current location to store with item i
double cost(tuple<int, int, int, int, bool> &current, tuple<int, int, int, int, bool> &item) {
  double length = abs(get<0>(current) - get<0>(item));
  double height = abs(get<1>(current) - get<1>(item));
  double distance = hypot(length, height);
  return (distance * gas) + get<2>(item);
}

double backtrack(vector<string> &path,
                 tuple<int, int, int, int, bool> &current,
                 int index,
                 map<string, vector<tuple<int, int, int, int, bool>>> &stores,
                 double result) {
  if (index == path.size()) {
    result += cost(current, home);
    if (DEBUG) {
      for (int i = 0; i < path.size(); i++) cout << path[i] << ' ';
      cout << result << endl;
    }
    minimum = (minimum > result) ? result : minimum;
    return 0.0;
  }

  vector<tuple<int, int, int, int, bool>> locations = stores[path[index]];
  // For each store that sells item (at path[index]))
  for (int i = 0; i < locations.size(); i++) {
    double travel = 0.0;
    tuple<int, int, int, int, bool> location = locations[i];
    if (get<4>(current)) {
      travel = cost(current, home) + cost(home, location);
      //cout << "current->home: " << cost(current, home) << endl;
      //cout << "home->location: " << cost(home, location) << endl;
    } else {
      travel = cost(current, location);
    }
    // If we visit some location, also pick up any items that it may have
    // further down our 'path'

    backtrack(path, location, index + 1, stores, travel + result);
  }

  return result;
}

int main() {
  cout.precision(9);
  int num;
  cin >> num;

  for (int i = 0; i < num; i++) {
    minimum = DBL_MAX;
    int num_stores, num_items;
    cin >> num_items >> num_stores >> gas;

    vector<string> order;
    map<string, bool> items;
    map<string, vector<tuple<int, int, int, int, bool>>> stores;
    map<int, vector<tuple<string, int>>> inventory;
    for (int j = 0; j < num_items; j++) {
      string item;
      cin >> item;
      if (item.back() == '!') {
        item.pop_back();
        items[item] = true;
      }
      else {
        items[item] = false;
      }
      order.push_back(item);
    }

    for (int j = 0; j < num_stores; j++) {
      int x, y;
      cin >> x >> y;

      string info;
      while(cin >> info) {
        int pos = info.find(':');
        string item = info.substr(0, pos);
        int price = stoi(info.substr(pos + 1));
        stores[item].push_back(make_tuple(x, y, price, j, items[item]));
        inventory[j].push_back(make_tuple(item, price));
        if(cin.peek() == '\n') break;
      }
    }

      vector<int> indexes;
      for (int j = 0; j < num_items; j++) indexes.push_back(j);

      double min = DBL_MAX;
      do {
        vector<string> path;
        for (int j = 0; j < num_items; j++) {
          path.push_back(order[indexes[j]]);
        }
        backtrack(path, home, 0, stores, 0.0);
      } while (next_permutation(indexes.begin(), indexes.begin() + num_items));

      cout << fixed << "Case #" << (i + 1) << ": " << minimum << endl;

  }
  return 0;
}
