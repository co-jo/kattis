#include <iostream>

using namespace std;

double table[10][101];

int main() {

    int k, n;
    while(cin >> k && cin >> n) {
        k += 1.0;
        for (int i = 0; i < k; i++) {
            table[i][1] = (1.0/k);
        }

        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < k; i++) {
                if (i - 1 >= 0) table[i][j] += table[i-1][j-1] * (1.0/k);
                if (i >= 0) table[i][j] += table[i][j-1] * (1.0/k);
                if (i + 1 < k) table[i][j] += table[i+1][j-1] * (1.0/k);
            }
        }

        double ratio = 0.0;
        for (int i = 0; i < k; i++) {
            ratio += table[i][n] * 100.0;
        }

        printf("%.9f\n", ratio);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 101; j++)
                table[i][j] = 0;
    }

    return 0;
}
