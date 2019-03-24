#include <iostream>
#include <vector>

using namespace std;

vector<int> match(2000, -1);

int matching(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    if (visited[node]) return 0;
    visited[node] = 1;

    for (int edge : graph[node]) {
        if (match[edge] == -1 || matching(match[edge], graph, visited)) {
            match[edge] = node;
            return 1;
        }
    }
    return 0;
}

int main() {

    int n, m;
    cin >> n >> m;

    int times, t;
    vector<vector<int>> nodes(n+m+1);
    for (int i = 0; i < n; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> t;
            nodes[i].push_back(t);
            nodes[n+t].push_back(i);
        }
    }

    int matchings = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n+m+1);
        matchings += matching(i, nodes, visited);
    }

    cout << matchings << endl;

    return 0;
}

