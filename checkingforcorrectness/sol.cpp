#include <iostream>

long long mod = 10000;

using namespace std;

int modpow(long x, long long n) {
    if (!n) return 1 % mod;
    int u = modpow(x, n/2);
    u = (u * u) % mod;
    // If odd, must multiply once by x.
    if (n % 2 == 1) {
        u = (u * x) % mod;
    }
    return u;
}

int main() {

    char op;
    long long left, right;

    while(cin >> left) {
        cin >> op >> right;
        if (op == '+') {
            cout << (left + right) % mod << endl;
        } else if (op == '^') {
            cout << modpow(left, right) % mod << endl;
        } else if (op == '*') {
            cout << ((left % mod) * (right % mod)) % mod << endl;
        }
    }

    return 0;
}

