#include <iostream>
#include <algorithm>
#include <cstring>

#define DEBUG 1
#define MAX 1000000000

using namespace std;

int round(int x) {
    return ((x % 10) <= 4) ? (x - x % 10) : (x + (10 - x % 10));
}

// Calculate the sum of the sub-arr[i...j]
int sum(int i, int j, int *arr) {
    return arr[j] - arr[i];
}

int main() {
    int item, items, dividers;
    cin >> items >> dividers;

    int prices[2002] = {};

    for (int i = 0; i < items; i++) {
        cin >> item;
        prices[i] = item;
    }

    int table[22][2002];

    int prefix[2002] = { 0 };
    // Calculate prefix array, from there we can calculate a suffix sum.
    for (int i = 1; i <= items; i++) {
        prefix[i] = prices[i - 1] + prefix[i - 1];
    }

    fill(&table[0][0], &table[dividers+1][items+1], MAX);

    // No dividers
    for (int j = 1; j <= items; j++) {
        table[0][j] = round(prefix[j]);
    }

    // The most obvious way to view this problem is some variation of the rod-cutting
    // problem, with some range queries in the mix. Generally the sub-structure
    // can be viewed as: If we know the optimal sum for up to the j'th item, does
    // adding another divider reduce the total cost.
    for (int i = 1; i <= dividers; i++) {
        for (int j = 1; j <= items; j++) {
            // If we add a divider at position j, does it make it better?
            for (int k = 0; k <= items; k++) {
                int range = sum(k, j, prefix);
                // range is the upper half of the split, meaning that table[i-1][k],
                // the lower half is already optimal at this point.
                table[i][j] = min(round(range) + table[i-1][k], table[i][j]);
            }
        }
    }

    if (DEBUG) {
        for (int i = 0; i <= dividers; i++) {
            for (int j = 0; j <= items; j++) {
                cout << table[i][j] << ' ';
            }
            cout << endl;
        }
    }

    cout << table[dividers][items] << endl;

    return 0;
}
