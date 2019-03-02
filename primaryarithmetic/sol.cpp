#include <iostream>

using namespace std;

int main() {

    long long a, b;
    while(cin >> a >> b) {
        if (!(a+b)) break;

        int ops = 0, c = 0;
        while (a > 0 || b > 0) {
            int e = a % 10;
            int d = b % 10;

            if (c + e + d >= 10) ops += 1;
            c = ((c + e + d) / 10);

            a /= 10;
            b /= 10;
        }
        if (!ops) {
            printf("No carry operation.\n");
        } else if (ops == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", ops);
        }
    }

    return 0;
}

