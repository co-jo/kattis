#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX 100000000

using namespace std;

int costs[1001];
int table[1001][1001];

int main() {

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            table[i][j] = MAX;
        }
    }

    int n = 0, start = 2;
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d\n", &costs[i]);
    }
    table[start][1] = costs[start];

    queue<pair<int, int>> search;
    search.push({start, 1});

    while(!search.empty()) {
        pair<int, int> move = search.front();
        search.pop();

        int i, jump;
        tie(i, jump) = move;
        int cost = table[i][jump];

        int back = i-jump;
        if (back >= 1 && cost + costs[back] < table[back][jump]) {
            table[back][jump] = cost + costs[back];
            search.push({back, jump});
        }

        int forward = i+jump+1;
        if (forward <= n && (cost + costs[forward]) < table[forward][jump+1]) {
            table[forward][jump+1] = cost + costs[forward];
            search.push({forward, jump+1});
        }
    }

    int cheapest = MAX;
    for (int i = 1; i <= n; i++) {
        cheapest = min(cheapest, table[n][i]);
    }

    printf("%d\n", cheapest);

    return 0;
}

