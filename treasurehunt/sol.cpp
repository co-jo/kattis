#include <iostream>

#define MAX 202

using namespace std;

char map[MAX][MAX];
bool visited[MAX][MAX];
int moves = 0;
int rows, cols;

void traverse(int x, int y) {

    if (x > rows || y > cols || x < 1 || y < 1) {
        cout << "Out" << endl; return;
    } else if (visited[x][y]) {
        cout << "Lost" << endl; return;
    }

    visited[x][y] = true;
    if (map[x][y] == 'N') {
        moves += 1;
        traverse(x - 1, y);
    } else if (map[x][y] == 'S') {
        moves += 1;
        traverse(x + 1, y);
    } else if (map[x][y] == 'W') {
        moves += 1;
        traverse(x, y - 1);
    } else if (map[x][y] == 'E') {
        moves += 1;
        traverse(x, y + 1);
    } else if (map[x][y] == 'T') {
        cout << moves << endl; return;
    }

    return;
}

int main() {

    cin >> rows >> cols;

    string row;
    for (int i = 1; i <= rows; i++) {
        cin >> row;
        for (int j = 1; j <= cols; j++){
            map[i][j] = row[j - 1];
        }
    }
    traverse(1, 1);

    return 0;
}
