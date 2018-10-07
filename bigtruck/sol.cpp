#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <climits>
#include <queue>

using namespace std;


map<int, vector<pair<int, int>>> edges;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;

int main() {
    int num;
    cin >> num;

    string line;
    // Consume '\n'.
    getline(cin, line);
    // Actual data.
    getline(cin, line);

    stringstream stream(line);

    int items[102] = { 0 };
    int picked[102] = { 0 };
    int distances[102];

    int count;
    for (int i = 1; i <= num; i++) {
        stream >> count;
        items[i] = count;
    }

    int num_edges;
    cin >> num_edges;
    getline(cin, line);


    for (int i = 0; i < num_edges; i++) {
        int from, to, length;
        getline(cin, line);
        stringstream stream(line);
        stream >> from >> to >> length;
        // Construct graph model.
        edges[from].push_back({to, length});
        edges[to].push_back({from, length});
    }

    for (int i = 0; i <= num; i++) distances[i] = INT_MAX;

    distances[1] = 0;
    picked[1] = items[1];
    // Try Dijkstra
    pqueue.push({0, 1});
    while (!pqueue.empty()) {
        int from = pqueue.top().second; pqueue.pop();

       for (auto edge: edges[from]) {
            int to, length;
            tie(to, length) = edge;

            if ((distances[from] + length) < distances[to]) {
                distances[to] = distances[from] + length;
                picked[to] = picked[from] + items[to];
                pqueue.push({distances[to], to});
            } else if(distances[to] == (distances[from] + length)) {
                picked[to] = max(picked[to], picked[from] + items[to]);
            }
       }
    }

    int distance = distances[num];
    //for (int i = 1; i <= num; i++) cout << distances[i] << ' ';
    if (distance == INT_MAX) {
        cout << "impossible" << endl;
    } else {
        cout << distance << ' ' << picked[num] << endl;
    }


    return 0;
}
