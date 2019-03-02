#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

int main() {

    int n, c;
    cin >> n;

    vector<int> citations(MAX + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c > MAX) c = MAX;
        citations[c] += 1;
    }

    // Take the 'reverse' prefix-sum.
    for (int i = MAX - 1; i >= 0; i--) {
        citations[i] = citations[i] + citations[i + 1];
    }

    for (int i = MAX; i >= 0; i--) {
        if (citations[i] >= i) {
            cout << i; break;
        }
    }

    return 0;
}
