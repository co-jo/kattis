#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MAX 200000

using namespace std;

vector<vector<int>> tree;
vector<int> depths, indicies;

void dfs(int id, int depth, int parent) {
    indicies.push_back(id);
    depths.push_back(depth);

    for (auto node : tree[id]) {
        if (node != parent) {
            dfs(node, depth + 1, id);
            indicies.push_back(id);
            depths.push_back(depth);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, to, from;
    cin >> nodes;

    tree.resize(nodes + 1);
    for (int i = 1; i < nodes; i++) {
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(1, 0, 0);

    unordered_map<int, int> positions;
    for (int i = 1; i <= depths.size(); i++) {
        positions[indicies[i]] = i;
    }

    int limit = floor(log2(2 * nodes - 1)) + 1;
    vector<vector<int>> ranges(2 * nodes, vector<int>(limit + 1, MAX));
    vector<vector<int>> ancestors(2 * nodes, vector<int>(limit + 1, MAX));

    // Setup RMQ.
    for (int i = 0; i < indicies.size(); i++) {
        ranges[i][0] = depths[i];
        ancestors[i][0] = indicies[i];
    }

    for (int i = 1; i <= limit; i++) {
        for (int j = 1; j + (1 << i) <= (2 * nodes - 1); j++) {
            if (ranges[j][i - 1] < ranges[j + (1 << (i - 1))][i - 1]) {
                ancestors[j][i] = ancestors[j][i - 1];
                ranges[j][i] = ranges[j][i - 1];
            } else {
                ancestors[j][i] = ancestors[j + (1 << (i - 1))][i - 1];
                ranges[j][i] = ranges[j + (1 << (i - 1))][i - 1];
            }
        }
    }

    int ancestor;
    long long sum = 0;
    for (int i = 1; i <= nodes; i++) {
        for (int j = i * 2; j <= nodes; j += i) {
            int right = positions[i], left = positions[j];
            if (right < left) swap(right, left);
            int power = log2((right - left) + 1);
            if (ranges[left][power] < ranges[right - (1 << power) + 1][power]) {
                ancestor = ancestors[left][power];
            } else {
                ancestor = ancestors[right - (1 << power) + 1][power];
            }
            sum += (depths[right] + depths[left]) - 2 * depths[positions[ancestor]] + 1;
        }
    }

    cout << sum << endl;

    return 0;
}
