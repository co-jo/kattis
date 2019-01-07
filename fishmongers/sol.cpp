#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

    int fish, mongers, weight;
    cin >> fish >> mongers;

    vector<long long> fishes;
    map<int, int> prices;
    for (int i = 0; i < fish; i++) {
        cin >> weight;
        fishes.push_back(weight);
    }

    sort(fishes.begin(), fishes.end());

    int amount, price;
    for (int i = 0; i < mongers; i++) {
        cin >> amount >> price;
        prices[price] += amount;
    }

    long long monies = 0;
    for (auto it = prices.rbegin(); it != prices.rend(); it++) {
        if (!fishes.size()) break;
        for (int i = 0; i < it->second && fishes.size() > 0; i++) {
            monies += fishes.back() * it->first;
            fishes.pop_back();
        }
    }

    cout << monies << endl;

    return 0;
}
