#include <iostream>
#include <cmath>

using namespace std;

int binom(int n, int k) {
    if (k == n || k == 0) {
        return 1;
    }
    return binom(n-1, k-1) + binom(n-1, k);
}

int main() {

    int cases;
    cin >> cases;

    double r, s, x, y, w;
    for (int i = 0 ; i < cases; i++) {
        // Binomail Distribution.
        cin >> r >> s >> x >> y >> w;
        double sum = 0.0;
        double p = ((s - r) + 1)/s;
        for (int j = x; j <= y; j++) {
            sum += binom(y, j) * pow(p, j) * pow(1-p, y-j);
        }

        if (sum * w > 1) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }

    return 0;
}
