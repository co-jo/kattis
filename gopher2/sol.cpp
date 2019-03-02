#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

bitset<200> visited;

int augment(int i, vector<vector<int>> &graph, vector<int> &match) {
    if (visited[i]) return 0;
    visited[i] = true;

    for (int j = 0; j < graph[i].size(); j++) {
        int n = graph[i][j];
        if (match[n] == -1 || augment(match[n], graph, match)) {
            match[n] = i;
            return 1;
        }
    }
    return 0;
}

int main() {

    float x,y;
    int n, m, s, v;

    while(cin >> n >> m >> s >> v) {

        vector<pair<float, float>> gophers;
        vector<pair<float, float>> holes;

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            gophers.push_back({x,y});
        }

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            holes.push_back({x,y});
        }

        vector<int> match(n + m, -1);
        vector<vector<int>> graph(n + m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hypot(gophers[i].first - holes[j].first, gophers[i].second - holes[j].second)/v < s) { 
                    graph[i].push_back(n + j);
                    graph[n + j].push_back(i);
                }
            }
        }

        int safe = 0;
        for (int i = 0; i < n; i++) {
            visited.reset();
            safe += augment(i, graph, match);
        }

        cout << n - safe << endl;
    }

    return 0;
}
