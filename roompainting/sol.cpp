#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m;

    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
    }

    sort(sizes.begin(), sizes.end());

    long long wasted = 0;
    for (int i = 0; i < m; i++) {
        cin >> r;
        wasted += *lower_bound(sizes.begin(), sizes.end(), r) - r;
    }

    cout << wasted << endl;

    return 0;
}
