#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> suffix;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i - 1 << ' ';
            if (i != n/i) suffix.push_back(n/i - 1);
        }
    }

    for (int i = suffix.size() - 1; i >= 0; i--) {
        cout << suffix[i] << ' ';
    }
    cout << endl;

    return 0;
}
