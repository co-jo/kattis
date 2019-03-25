#include <iostream>

#define MIN -10000000001

using namespace std;

long long input[5000];
long long table[5001][5001];
long long include[5001][5001];

int main() {

    int n, k;
    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; i++ ){
        scanf("%lld", &input[i]);
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            include[i][j] = table[i][j] = (include[i][j-1] + input[j-1]);
        }
        for (int j = i+1; j <= n; j++) {
            include[i][j] = max(table[i-1][j-1], include[i][j-1]) + input[j-1];
            table[i][j] = max(include[i][j], table[i][j-1]);
        }
    }

    printf("%lld\n", table[k][n]);

    return 0;
}
