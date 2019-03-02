#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;

    if (k >= n) {
        cout << n - 1 << endl;
    } else {
        long long j = (n - 1)/k;
        long long l = (n - 1) - k * j;
        if (j == 1) k--;
        cout << k + l + 1<< endl;
    }

    return 0;
}
