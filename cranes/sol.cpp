#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <tuple>
#include <algorithm>

using namespace std;

inline int area(bitset<16> set, vector<tuple<int, int, int>> &cranes) {
    int area = 0;
    for (int i = 0; i < 16; i++) {
        if (set[i]) {
            tuple<int, int, int> one = cranes[i];
            for (int j = i + 1; j < 16; j++) {
                if (set[j]) {
                    tuple<int, int, int> two = cranes[j];
                    double distance = hypot(get<0>(two) - get<0>(one), get<1>(two) - get<1>(one));
                    if (distance <= (get<2>(two) + get<2>(one))) return -1;
                }
            }
            area += (get<2>(one) * get<2>(one));
        }
    }
    return area;
}

int main() {
    int cases, cranes;
    cin >> cases;

    for (int i = 0 ; i < cases; i++) {
        cin >> cranes;
        vector<tuple<int, int, int>> crane;

        int x, y, r;
        for (int j = 0; j < cranes; j++) {
            cin >> x >> y >> r;
            crane.push_back({x,y,r});
        }

        int ans = 0;
        for (int j = 1; j <= ((1 << cranes) - 1); j++) {
            bitset<16> set(j);
            ans = max(ans, area(set, crane));
        }
        cout << ans << endl;
    }
}
