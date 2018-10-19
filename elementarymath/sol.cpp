#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

map<long long, vector<long long>> graph;
vector<pair<long long, long long>> pairs;
vector<string> results(7500);

long long augment(long long node, vector<long long> &visited, unordered_map<long long, long long> &matched) {
    if (visited[node]) return 0;
    visited[node] = 1;

    for (long long i = 0; i < graph[node].size(); i++) {
        long long to = graph[node][i];
        if (matched[to] == -1 || augment(matched[to], visited, matched)) {
            matched[to] = node;
            return 1;
        }
    }

    return 0;
}

int main() {

    long long num;
    cin >> num;

    long long a, b;

    // It is critical that we use as long type, as a,b can be in the range of 10^-6 : 10^6
    vector<long long> visited(num, 0);
    // Important step here is to be able to map both the pairs and results to
    // some singular index.
    unordered_map<long long, long long> matched;
    for (long long i = 0; i < num; i++) {
        cin >> a >> b;

        graph[i] = { a * b, a - b, a + b };
        pairs.push_back({a, b});

        matched[a * b] = -1;
        matched[a - b] = -1;
        matched[a + b] = -1;
    }

    long long total = 0;
    for (long long i = 0; i < num; i++) {
        visited.assign(num, 0);
        total += augment(i, visited, matched);
    }

    if (total != num) {
        cout << "impossible" << endl;
    } else {
        long long a, b;
        string sign;
        for (auto it = matched.begin(); it != matched.end(); it++) {
            if (it -> second != -1) {
                tie(a, b) = pairs[it->second];
                    if (it->first == (a * b)) {
                        sign = " * ";
                    } else if (it->first == (a - b)) {
                        sign = " - ";
                    } else {
                        sign = " + ";
                    }
                results[it->second] = to_string(a) + sign + to_string(b) + " = " + to_string(it->first);
            }
        }
        for (long long i = 0; i < total; i++) {
            cout << results[i] << endl;
        }
    }

    return 0;
}
