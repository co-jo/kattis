#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

int res[12][12];
bool found = false;
vector<int> path;

int scan(int p, bitset<12> visited, int n) {

    if (visited[p]) return 0;
    visited[p] = 1;

    if (visited.count() == n) {
        if (!found) found = true;
        return 1;
    }

    int val = 0;
    for (int i = 0; i < n; i++) {
        if (i == p) continue;
        if (!res[p][i]) {
            if (!found) path.push_back(i);
            val += scan(i, visited, n);
            if (!found) path.pop_back();
        }
    }

    return val;
}

int main() {

    int c, n, m;
    cin >> c;

    string colour;
    for (int i = 0; i < c; i++) {
        cin >> n;

        vector<string> index;
        unordered_map<string, int> colours;
        for (int j = 0; j < n; j++) {
            cin >> colour;
            colours[colour] = j;
            index.push_back(colour);
        }

        cin >> m;
        string first, second;
        for (int j = 0; j < m; j++) {
            cin >> first >> second;
            res[colours[first]][colours[second]] = 1;
            res[colours[second]][colours[first]] = 1;
        }

        int valid = 0;
        for(int j = 0; j < n; j++) {
            bitset<12> visited;
            if (!found) path.push_back(j);
            valid += scan(j, visited, n);
            if (!found) {
                path.pop_back();
            }
        }
        cout << valid << endl;

        for (auto ele : path) {
            cout << index[ele] << ' ';
        }
        cout << endl;

        found = false;
        path.clear();
        memset(&res, 0, sizeof(res));
    }


    return 0;
}

