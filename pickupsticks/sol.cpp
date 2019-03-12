#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// Topological Sort.
int main() {

    int n, m, a, b;
    cin >> n >> m;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> search;
    vector<int> degrees(n+1);
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        degrees[b] += 1;
        // a -> b
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!degrees[i]) {
            search.push(i);
        }
    }

    vector<int> path;
    while (!search.empty()) {
        int head = search.front();
        search.pop();

        path.push_back(head);
        for (int edge : graph[head]) {
            degrees[edge] -= 1;
            if (!degrees[edge]) {
                search.push(edge);
            }
        }
    }

    if (path.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int node : path) {
            cout << node << '\n';
        }
    }

    return 0;
}

