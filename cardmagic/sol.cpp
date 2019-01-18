#include <iostream>

using namespace std;

int main() {

    int mod = 1000000009;
    int decks, cards, target;
    cin >> decks >> cards >> target;

    int table[decks + 1][target + 1];
    for (int i = 0; i <= decks; i++) {
        for (int j = 0; j <= target; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 1; i <= cards; i++) {
        table[1][i] = 1;
    }

    for (int i = 2; i <= decks; i++) {
        for (int j = 1; j <= cards; j++) {
            for (int k = i + j - 1; k <= target; k++) {
                table[i][k] = (table[i][k] + table[i - 1][k - j]) % mod;
            }
        }
    }

    cout << table[decks][target] << endl;

    return 0;
}
