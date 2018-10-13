#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <deque>
#include <climits>
#include <set>
#include <string.h>

using namespace std;

//map<int, int> path;
//map<int, map<int, int>> graph;
map<int, map<int, int>> residual;

int path[500];
int graph[500][500];
// Breadth-First Search
bool search(vector<int> &visited, int source, int sink, int nodes) {

    visited[source] = true;
    queue<int> que; que.push(source);
    while (!que.empty()) {
        int from = que.front(); que.pop();
        for (int i = 0; i < nodes; i++) {
            if (graph[from][i] > 0 && !visited[i]) {
                que.push(i);
                visited[i] = true;          
                path[i] = from;
            }

        }
    }

    return visited[sink];
}

int main() {

    int num_nodes, num_edges, source, sink;
    cin >> num_nodes >> num_edges >> source >> sink;

    // Flow based problem.
    memset(graph, 0, sizeof(graph));
    memset(path, -1, sizeof(path));
    
    int start, end, weight;
    for (int i = 0; i < num_edges; i++) {
        cin >> start >> end >> weight;
        graph[start][end] = weight;
    }

    vector<int> visited(num_nodes, false);
    while (search(visited, source, sink, num_nodes)) {
        // Get min flow on the path -- this is the bottle neck.
        int path_flow = INT_MAX;

        for (int i = sink; i != source; i = path[i]) {
	   path_flow = min(path_flow, graph[path[i]][i]); 
        }

        for (int i = sink; i != source; i = path[i]) {
            graph[path[i]][i] -= path_flow;
            graph[i][path[i]] += path_flow;
        }

    	memset(path, -1, sizeof(path));
	fill(visited.begin(), visited.end(), false);
    }


    // Seach for all nodes in U. I.E: Those that are reachable and not 0.
   int _ = search(visited, source, sink, num_nodes);

   set<int> results;
   for (int i = 0; i < visited.size(); i++) {
	if (visited[i]) results.insert(i);
   }

   cout << results.size() << endl;
   for (auto it = results.begin(); it != results.end(); it++) {
       cout << *it << endl;
   }

    return 0;
}

