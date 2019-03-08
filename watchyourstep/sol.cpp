#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

bitset<2500> visited;
vector<vector<int>> table(2500);

void search(int node) {
    if (visited[node]) return;
    visited[node] = 1;

    for (int i : table[node]) {
        if (i == node) continue;
        search(i);
    }
}

int main() {

    int n, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b;
            if(b) table[i].push_back(j);
        }
    }

    int p = 0;
    for (int i = 0; i < n; i++) {
        visited.reset();
        search(i);

        bitset<2500> edges;
        for (int edge : table[i]) {
            edges[edge] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (visited[j] && !edges[j] && i != j) {
                p += 1;
            }
        }
    }

    cout << p << endl;

    return 0;
}

