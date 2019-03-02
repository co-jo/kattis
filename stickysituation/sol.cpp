#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    bool possible = false;
    for (int i = 0; i <= n - 3; i++) {
        long long a = sticks[i];
        long long b = sticks[i + 1];
        long long c = sticks[i + 2];
        if ((a + b) > c && (a + c) > b && (c + b) > a) {
            possible = true; break;
        }
    }

    if (possible) cout << "possible";
    else cout << "impossible";

    return 0;
}
