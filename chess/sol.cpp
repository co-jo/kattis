#include <iostream>
#include <map>
#include <vector>
#include <climits>

#define DEBUG 0
#define MAX 5
#define SIZE 8

using namespace std;


vector<char> chars = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' , 'H' };
vector<vector<map<pair<int, int>, int>>> table(SIZE, vector<map<pair<int, int>, int>>(SIZE));

bool bound(int i, int j) {
    return (i < SIZE && i >= 0 && j < SIZE && j >= 0);
}

void path(int i, int j, int a, int b, int moves) {
    cout << chars[j] << ' ' << i + 1 << ' ';
    if (i == a && j == b) return;
    pair<int, int> point;
    for (auto it = table[i][j].begin(); it != table[i][j].end(); it++) {
        int current = table[it->first.first][it->first.second][{a,b}];
        if (current < moves && it->second == 1) {
            moves = current;
            point = it->first;
        }
    }
    return path(point.first, point.second, a, b, table[point.first][point.second][{a,b}]);
}

// A much easier and better way is just to take the diagonals of both points, and the interseciton
// is there midpoint. Here, I specifically wanted to try a 'DP' like solution.
int main() {

    for (int i = 0 ; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                for (int l = 0; l < SIZE; l++) {
                    table[i][j][{k, l}] = MAX;
                }
            }
            table[i][j][{i,j}] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k : {1, -1}) {
                for (int l : {1, -1}) {
                    for (int a = i + k, b = j + l; bound(a, b) != false; a += k, b += l) {
                        // For each position reachable from our current position.
                        for (auto it = table[a][b].begin();  it != table[a][b].end(); it++) {
                            table[i][j][{it->first}] = min(table[i][j][{it->first}], it->second + 1);
                        }
                        for (auto it = table[i][j].begin();  it != table[i][j].end(); it++) {
                            table[a][b][{it->first}] = min(table[a][b][{it->first}], it->second + 1);
                        }
                    }
                }
            }
        }
    }

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        char start_col, end_col;
        int start_row, end_row;

        cin >> start_col >> start_row  >> end_col >> end_row;
        start_row--, end_row--;

        int moves = table[start_row][start_col - 'A'][{end_row, end_col - 'A'}];
        if (moves >= 5) {
            cout << "Impossible";
        } else {
            cout << moves << ' '; path(start_row, start_col - 'A', end_row, end_col - 'A', moves);
        }
        cout << endl;

    }

    return 0;
}
