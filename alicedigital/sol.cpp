#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve (vector<int> &vals, int target) {

    vector<int> indexes;
    // Find the index of each number, then expand left and right until we hit 'target'
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i] == target) {
            indexes.push_back(i);
        }
    }

    int sum = 0;
    for (int i = 0; i < indexes.size(); i++) {

        int ele = target, current = target;
        int left = indexes[i], right = indexes[i];

        while (--left >= 0 && vals[left] > ele) {
            current += vals[left];
            ele = min(ele, vals[left]);
        }

        while (++right < vals.size() && vals[right] > ele) {
            current += vals[right];
            ele = min(ele, vals[right]);
        }

        sum = max(sum, current);
    }

    return sum;
}

int main() {

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int nums, num, target;
        cin >> nums >> target;

        vector<int> vals;
        for (int j = 0; j < nums; j++) {
            cin >> num;
            vals.push_back(num);
        }
        cout << solve(vals, target) << endl;
    }

    return 0;
}
