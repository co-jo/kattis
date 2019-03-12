#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000000

using namespace std;

vector<vector<char>> grid(1000, vector<char>(1000));
vector<vector<int>> joe(1000, vector<int>(1000, MAX));
vector<vector<int>> fire(1000, vector<int>(1000, MAX));

void fill(vector<vector<int>> &table, vector<pair<int, int>> &start, int rows, int cols) {

    queue<pair<int, int>> search;
    for (auto cord : start) {
        table[cord.first][cord.second] = 0;
        search.push(cord);
    }

    while(!search.empty()) {

        pair<int, int> head = search.front();
        search.pop();

        int y = head.first, x = head.second;
        if (grid[y][x] == '#') continue;

        if (x >= 1 && table[y][x] + 1 < table[y][x-1]) {
            table[y][x-1] = table[y][x] + 1;
            search.push({y, x-1});
        }
        if (x < cols - 1 && table[y][x] + 1 < table[y][x+1]) {
            table[y][x+1] = table[y][x] + 1;
            search.push({y, x+1});
        }
        if (y >= 1 && table[y][x] + 1 < table[y-1][x]) {
            table[y-1][x] = table[y][x] + 1;
            search.push({y-1, x});
        }
        if (y < rows - 1 && table[y][x] + 1 < table[y+1][x]) {
            table[y+1][x] = table[y][x] + 1;
            search.push({y+1, x});
        }
    }

}

int main() {

    int r, c;
    cin >> r >> c;

    vector<pair<int, int>> fvec;
    vector<pair<int, int>> jvec;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'J') {
                jvec.push_back({i, j});
            } else if (grid[i][j] == 'F') {
                fvec.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> exits;
    for (int i = 0; i < r; i++) {
        if (grid[0][i] == '.' || grid[0][i] == 'J') exits.push_back({0, i});
        if (grid[r-1][i] == '.' || grid[r-1][i] == 'J') exits.push_back({r-1, i});
    }
    for (int i = 0; i < c; i++) {
        if (grid[i][0] == '.' || grid[i][0] == 'J') exits.push_back({i, 0});
        if (grid[i][c-1] == '.' || grid[i][c-1] == 'J') exits.push_back({i, c-1});
    }

    fill(fire, fvec, r, c);
    fill(joe, jvec, r, c);

    int ans = MAX;
    bool possible = false;
    for (pair<int, int> ele : exits) {
        if (joe[ele.first][ele.second] < fire[ele.first][ele.second]) {
            ans = min(ans, joe[ele.first][ele.second]+1);
            possible = true;
        }
    }

    if (possible) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;

}

