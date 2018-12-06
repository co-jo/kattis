#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> const &lhs, pair<int, int> const &rhs) {
//    if (lhs.first < rhs.first || lhs.first == rhs.first && rhs.second > lhs.second) {
//        return true;
//    } else {
//        return false;
//    }
    return lhs.second < rhs.second;
}

int rooms(vector<pair<int, int>> &minions) {
    int i = 0, count = 0, size = minions.size();
    while(i < size) {
        int max = minions[i].second;
        // Because we sort by the greater number in the pair, max is always
        // going to be less than the max of any future ranges. As long as the future min
        // is less than the current max, it will fit in the range. We can do this greedily because
        // it does not matter which of the possible ranges a minion falls into.
        while (i < size && minions[i].first <= max) {
            i++;
        }
        count++;
    }
    return count;
}

int main() {


    int low, high, num;
    cin >> num;

    vector<pair<int, int>> minions;
    for (int i = 0; i < num; i++) {
        cin >> low >> high;
        minions.push_back({low, high});
    }

    sort(minions.begin(), minions.end(), cmp);

    //for (auto minion : minions) {
    //    cout << minion.first << ' ' << minion.second << endl;
    //}

    cout << rooms(minions) << endl;

    return 0;
}
