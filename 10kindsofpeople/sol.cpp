#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

int rows, cols;
int table[MAX][MAX];
int marked[MAX][MAX];

void traverse(int tag, int state, int x, int y) {
    // Bounds check.
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    // Validity & visited check.
    if (marked[x][y] || state != table[x][y]) return;

    marked[x][y] = tag;
    traverse(tag, table[x][y], x + 1, y);
    traverse(tag, table[x][y], x - 1, y);
    traverse(tag, table[x][y], x, y + 1);
    traverse(tag, table[x][y], x, y - 1);

    return;
}

// Basic graph traversal.
int main() {

    cin >> rows >> cols;

    string line;
    int queries, r1, c1, r2, c2;
    // Eat newline.
    getline(cin, line);
    for (int i = 0; i < rows; i++) {
        getline(cin, line);
        for (int j = 0; j < cols; j++){
            table[i][j] = line[j] - '0';
        }
    }


    int tag = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            if (!marked[i][j]){
                traverse(++tag, table[i][j], i, j);
            }
        }
    }

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (marked[r1 - 1][c1 - 1] == marked[r2 - 1][c2 - 1]) {
            if (table[r1 - 1][c1 - 1]) cout << "decimal" << endl;
            else cout << "binary" << endl;
        } else {
            cout << "neither" << endl;
        }
    }
    return 0;
}
