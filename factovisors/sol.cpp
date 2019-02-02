#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {

    int m, n;
    while(cin >> n && cin >> m) {
        int d = m;
        unordered_map<int, int> factors;
        for (int i = 2; i <= sqrt(m);) {
            if (d % i == 0) {
                d /= i;
                factors[i] += 1;
            } else {
                i += 1;
            }
        }
        factors[d] += 1;

        bool valid = true;
        for (pair<int, int> ele : factors) {
            int count = 0;
            for (int i = 1; i <= ele.second; i++) {
                count += (n / pow(ele.first, i));
            }
            if (count < ele.second) valid = false;
        }

        if (valid || (!n && m == 1)) {
            cout << m << " divides " << n << "!" << endl;
        } else {
            cout << m << " does not divide " << n << "!" << endl;
        }
    }
}
