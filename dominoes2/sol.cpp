#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Depth-first-search, and returned the number of nodes marked.
int dfs(int id, vector<vector<int>> &graph, vector<bool> &visited) {
    if (visited[id]) return 0;
    visited[id] = true;
    int num = 1;
    for (auto edge : graph[id]) {
        num += dfs(edge, graph, visited);
    }
    return num;
}

int main() {
    int cases;
    cin >> cases;

    int dominoes, links, pushed;
    for (int i = 0; i < cases; i++) {
        cin >> dominoes >> links >> pushed;

        int first, second, dominoe;
        vector<vector<int>> graph(dominoes+1);
        for (int j = 0; j < links; j++) {
            cin >> first >> second;
            graph[first].push_back(second);
        }
        int knocked = 0;
        vector<bool> visited(dominoes+1, false);
        // Potential components.
        for (int j  = 0; j < pushed; j++) {
            cin >> dominoe;
            knocked += dfs(dominoe, graph, visited);
        }
        cout << knocked << endl;
    }

    return 0;
}

