#include <iostream>
#include <queue>

#define MAX 10000001

using namespace std;

int grid[1000][1000];
int table[1000][1000];

int main() {

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            table[i][j] = MAX;
        }
    }

    queue<pair<int, int>> search;
    for (int j = 0; j < r; j++) {
        search.push({j, 0});
        table[j][0] = grid[j][0];
    }

    while(!search.empty()) {
        pair<int, int> pos = search.front();
        search.pop();

        int x = pos.first;
        int y = pos.second;

        if (y >= 1) {
            if (table[x][y] < table[x][y-1]) {
                table[x][y-1] = max(grid[x][y-1], table[x][y]);
                search.push({x, y-1});
            }
        }
        if (y < c - 1) {
            if (table[x][y] < table[x][y+1]) {
                table[x][y+1] = max(grid[x][y+1], table[x][y]);
                search.push({x, y+1});
            }
        }

        if (x >= 1) {
            if (table[x][y] < table[x-1][y]) {
                table[x-1][y] = max(grid[x-1][y], table[x][y]);
                search.push({x-1, y});
            }
        }
        if (x < r - 1) {
            if (table[x][y] < table[x+1][y]) {
                table[x+1][y] = max(grid[x+1][y], table[x][y]);
                search.push({x+1, y});
            }
        }
    }


    int s = MAX;
    for (int i = 0; i < r; i++) {
        s = min(s, table[i][c-1]);
    }
    cout << s << endl;

    return 0;
}

