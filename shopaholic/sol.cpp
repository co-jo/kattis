#include <iostream>
#include <algorithm>

#define MAX 200000

using namespace std;

int prices[MAX];

int main() {

    int items, item;
    cin >> items;

    for (int i = 0; i < items; i++) {
        cin >> prices[i];
    }

    sort(prices, prices + items);

    long long discount = 0;
    for (int i = items - 3; i >= 0; i -= 3) {
        discount += prices[i];
    }

    cout << discount << endl;

    return 0;
}
