#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int num, floors;
    cin >> num;

    int total = 0;
    deque<int> buildings;
    for (int i = 0; i < num; i++) {
        cin >> floors;
        buildings.push_back(floors);
    }

    sort(buildings.rbegin(), buildings.rend());

    // 'singles' marks how many times we removed a single floor from all buildings.
    int i = 0, singles = 0;
    for (; buildings.empty() == false; i++) {
        if ((buildings.front() - singles) >=  buildings.size()) {
            buildings.pop_front();
        } else {
            singles++;
            while (buildings.back() <= singles) {
                buildings.pop_back();
            }
        }
    }

    cout << i << endl;

    return 0;
}

