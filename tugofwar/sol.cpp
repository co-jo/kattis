#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 46000

using namespace std;

int main() {

    int people, weight, total = 0;
    cin >> people;

    vector<int> weights(people + 1, 0);
    for (int i  = 0; i < people; i++) {
        cin >> weight;
        weights[i] = weight;
        total += weight;
    }

    int table[people + 1][MAX] = { 1 };
    for (int i = 0; i < people; i++) {
        for (int j = people/2; j >= 0; j--) {
            for (int k = total; k >= 0; k--) {
                if (table[j][k]) {
                    table[j + 1][k + weights[i]] = 1;
                }
            }
        }
    }

    int lower = MAX;
    for (int i = 0; i <= total; i++) {
        if (table[people/2][i]) {
            if (abs((total - lower) - lower) > abs((total - i) - i)) {
                lower = i;
            }
        }
    }
    cout << min(lower, total - lower) << ' ' << max(lower, total - lower) << endl;

    return 0;
}
