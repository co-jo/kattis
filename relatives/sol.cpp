#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n;
    while(cin >> n) {
        if (!n) break;
        int m = n;
        vector<int> factor;
        for (int i = 2; i <= sqrt(m); i++) {
            if (n % i == 0) {
                factor.push_back(i);
            }
            while (n % i == 0) n /= i;
        }

        if (n > 1) m -= m/n;
        for (auto ele : factor) {
            if (ele) m -= (m / ele);
        }
        // Final factor.
        cout << m << endl;

    }

    return 0;
}
