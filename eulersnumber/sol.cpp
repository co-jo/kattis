#include <iostream>

int main() {

    int n;
    scanf("%d\n", &n);

    long double euler = 0.0;
    long double factorial = 1;
    for (int i = 0; i <= n; i++) {
        euler += 1.0/(long double)factorial;
        factorial *= (i + 1.0);
    }

    printf("%.16Lf\n", euler);

    return 0;
}

