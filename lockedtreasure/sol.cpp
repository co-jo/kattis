#include <iostream>

#define MAX 31

using namespace std;

int table[MAX][MAX];

int choose(int n, int k) {
    if (k == 0 || k == n) return 1;
    else if (table[n][k]) return table[n][k];
    table[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
    return table[n][k];
}

int main() {

    int c, n, m;
    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        cout << choose(n, m - 1) << endl;
    }

    return 0;
}
