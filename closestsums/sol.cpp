#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

set<int> choose(int *arr, int n) {
    set<int> sum;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum.insert(arr[i] + arr[j]);
        }
    }
    return sum;
}

int main() {

    int n, m, q;
    for (int c = 1; cin >> n; c++) {

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        set<int> sums = choose(arr, n);

        cin >> m;
        printf("Case %d:\n", c);
        for (int i = 0; i < m; i++) {
            cin >> q;

            auto it = sums.lower_bound(q);

            int h = *it, l;
            if (--it != sums.end()) l = *it;

            int closest = (abs(h - q) < abs(l - q)) ? h : l;

            printf("Closest sum to %d is %d.\n", q, closest);
        }
    }

    return 0;
}
