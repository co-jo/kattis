#include <iostream>

using namespace std;

int order[26][26];
int wins[26][26];

int main() {

    int n, m, c;
    cin >> n >> m;

    string ballot;
    for (int i = 0; i < m; i++) {
        cin >> c >> ballot;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                order[ballot[j] - 'A'][ballot[k] - 'A'] += c;
            }
        }
    }

    for (int l = 0; l < n; l++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (order[j][k] > order[k][j]) {
                    wins[j][k] = 1;
                    for (int i = 0; i < n; i++) {
                        if (i != k && i != j) {
                            wins[j][i] |= wins[k][i];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int win = 0;
        for (int j = 0; j < n; j++) {
            win += wins[i][j];
        }
        if (win >= n - 1) {
            cout << char('A' + i) << ": can win" << endl;
        } else {
            cout << char('A' + i) << ": can't win" << endl;
        }
    }

    return 0;
}

