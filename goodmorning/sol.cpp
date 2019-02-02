#include <iostream>

#define MAX 201

using namespace std;

int grid[4][4] = {
    {  1, 2, 3, -1  },
    {  4, 5, 6, -1  },
    {  7, 8, 9, -1  },
    { -1, 0, -1, -1 }
};

int table[MAX];

void paths(int s, int i, int j, int d) {

    if (s > MAX || i > 3 || j > 3 || grid[i][j] < 0 || d > 3) {
        return;
    }

    table[s] = s;
    int n = grid[i][j];
    // Press.
    paths(s * 10 + n, i, j, d + 1);
    paths(s * 10 + n, i + 1, j, d + 1);
    paths(s * 10 + n, i, j + 1, d + 1);
    // Don't press.
    paths(s, i + 1, j, d);
    paths(s, i, j + 1, d);

}

int main() {

    int cases, k;
    cin >> cases;

    for (int i = 0; i < 4; i++) {
        paths(0, 0, i, 0);
    }

    for (int i = 0; i < cases; i++) {
        cin >> k;
        int ans, min = MAX;
        for (int j = 0; j < MAX; j++) {
            if (!table[j]) continue;
            if (min > abs(j - k)) {
                min = abs(j - k);
                ans = j;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
