#include <iostream>
#include <vector>
#include <cmath>

#define error 0.00000001

using namespace std;

bool prime(int q) {
    if (q == 1) return false;
    for (int i = 2; i <= sqrt(q); i++) {
        if (q % i == 0) return false;
    }
    return true;
}

int main() {

    int q;
    cin >> q;

    for (double k = 1.0; k <= 29.0; k += 1.0) {
        double p = pow(q, 1.0/k);
        if (abs(p - round(p)) < error && prime(round(p))) {
            cout << "yes" << endl; return 0;
        }
    }
    cout << "no" << endl;

    return 0;
}

