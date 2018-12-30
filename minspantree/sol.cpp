#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

int find(int x, int *link) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b, int *link) {
    return find(a, link) == find(b, link);
}

void unite(int a, int b, int *size, int *link) {
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b) {
    return get<2>(a) < get<2>(b);
}

int main() {

    int nodes, edges;
    while (cin >> nodes && cin >> edges) {
        if (nodes == 0 && edges == 0) return 0;

        int link[nodes], size[nodes];
        for (int i = 0; i < nodes; i++) link[i] = i;
        for (int i = 0; i < nodes; i++) size[i] = 1;

        // Build the graph.
        int from, to, weight;
        vector<tuple<int, int, int>> graph;
        for (int i = 0; i < edges; i++) {
            cin >> from >> to >> weight;
            graph.push_back({from, to, weight});
        }

        // Sort the edges by weight.
        sort(graph.begin(), graph.end(), cmp);

        // Build the MST.
        int total = 0;
        vector<tuple<int, int, int>> mst;
        for (int i = 0; i < edges; i++) {
            int a = get<0>(graph[i]);
            int b = get<1>(graph[i]);
            if (!same(a, b, link)) {
                unite(a, b, size, link);
                total += get<2>(graph[i]);
                mst.push_back(graph[i]);
            }
        }

        for (int i = 0; i < mst.size() ;i++) {
            if (get<1>(mst[i]) < get<0>(mst[i])) {
                mst[i] = { get<1>(mst[i]), get<0>(mst[i]), get<2>(mst[i]) };
            }
        }

        // Sort lexograprhically
        sort(mst.begin(), mst.end());

        if (total == 0 || mst.size() < nodes - 1) {
            cout << "Impossible" << endl;
        } else {
            cout << total << endl;
            for (int i = 0; i < mst.size(); i++) {
                cout << min(get<0>(mst[i]), get<1>(mst[i])) << ' ' << max(get<1>(mst[i]), get<0>(mst[i])) << endl;
                //cout << get<0>(mst[i])<< ' ' << get<1>(mst[i]) << endl;
            }
        }
    }

    return 0;
}
