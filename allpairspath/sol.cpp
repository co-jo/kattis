#include <iostream>
#include <climits>
#include <array>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main() {

    while (true) {

        int nodes, edges, queries;
        cin >> nodes >> edges >> queries;

        vector<vector<long long>> graph(nodes, vector<long long>(nodes, LONG_MAX));

        if (nodes == 0) return 0;


        long long from, to, weight;
        for (int i = 0; i < edges; i++) {
            cin >> from >> to >> weight;
            // Important: Seems that for some edge, a lower value edge weight is given.
            graph[from][to] = min(weight, graph[from][to]);
        }

        for (int i = 0; i < nodes; i++) {
            // A node can potentially be given a negative edge weight to itself.
            graph[i][i] = graph[i][i] < 0 ? graph[i][i] : 0;
        }

        // Floyd-Warshall: O(n^3)
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                for (int k = 0; k < nodes; k++) {
                    // Only bother updating if there is a possible new path.
                    if (graph[j][i] != LONG_MAX && graph[i][k] != LONG_MAX) {
                        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                    }
                }
            }
        }

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                for (int k = 0; k < nodes; k++) {
                    // Have to be careful about considering intermediate nodes with a negative self-loop.
                    // This will give any path with it as an intermediate loop an automatic -INF path weight.
                    if (graph[k][k] < 0 && graph[i][k] != LONG_MAX && graph[k][j] != LONG_MAX) {
                        graph[i][j] = -LONG_MAX;
                    }
                }
            }
        }

        for (int i = 0; i < queries; i++) {
            cin >> from >> to;
            long long distance = graph[from][to];
            // No path realized.
            if (distance == LONG_MAX) {
                cout << "Impossible" << endl;
            }
            // Negative edge weight, thus arbitrarily small.
            else if (distance == -LONG_MAX) {
                cout << "-Infinity" << endl;
            } else {
                cout << distance << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
