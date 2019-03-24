#include <iostream>

using namespace std;

long long table[33][33];

int main() {

    int t, n, k;
    scanf("%d\n", &t);

    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= 32; j++) {
            table[i][j] = table[i][j-1] + table[i-1][j-1] + 1;
        }
    }

    for (int i = 0; i < t; i++) {
        scanf("%d %d\n", &n, &k);

        int drops = 0;
        for (int j = 0; j <= 32; j++) {
            if (table[k][j] >= n) {
                drops = j; break;
            }
        }

        if (!drops) {
            printf("Impossible\n");
        } else {
            printf("%d\n", drops);
        }
    }

    return 0;
}

