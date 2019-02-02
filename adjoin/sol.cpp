#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;

// Returns the node with greatest depth, and the depth itself.
pair<int, int> dfs(int id, int from, int val) {

    visited[id] = true;
    pair<int, int> depth = { val, id };
    for (auto to : graph[id]) {
        if (to == from) continue;
        pair<int, int> child = dfs(to, id, val + 1);
        if (child.first > depth.first) depth = child;
    }

    return depth;
}

int diameter(int root) {

    pair<int, int> start = dfs(root, -1, 0);
    pair<int, int> end = dfs(start.second, -1, 0);

    return end.first;
}


int main() {

    int nodes, edges, to, from;
    cin >> nodes >> edges;

    visited.resize(nodes, 1);
    graph.resize(nodes);
    for (int i = 0; i < edges; i++) {
        cin >> from >> to;
        visited[from] = 0;
        graph[from].push_back(to);
        visited[to] = 0;
        graph[to].push_back(from);
    }

    vector<int> diameters(3, 0);
    for (int i = 0; i < nodes; i++) {
        if (visited[i]) continue;
        diameters.push_back(diameter(i));
    }

    sort(diameters.begin(), diameters.end());

    int tail = diameters.size() - 1;
    vector<int> radius(3, 0);
    for (int i = tail; i >= tail - 2 && i >= 0; i--) {
        radius[tail - i] = (diameters[i] % 2) ? diameters[i]/2 + 1: diameters[i]/2;
    }

    // 1. The largest component contains the maximal diameter.
    // 2. The two largest form a new component with the maximal diameter (+1 for added edge).
    // 3. The second and third largest pass through the first to form the maximal (+2).
    cout << max(diameters.back(), max(radius[0] + radius[1] + 1, radius[1] + radius[2] + 2)) << endl;

    return 0;
}
