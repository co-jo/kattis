#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {

    int nums, num, prev = 0;
    cin >> nums;

    vector<int> input(nums);
    set<int> denominators;
    for (int i = 0; i < nums; i++) {
        cin >> input[i];
    }

    // For some i'th element, if we know the list of all the gcds, for every subset that includes
    // the (i-1)'th, we just then need to take the gcd of each of those factors with the i'th element.
    // Because we are bound to some a >= 1 and <= 100, we are only bounded by O(n).
    set<int> previous;
    for (int i = 0; i < nums; i++) {
        set<int> current;
        current.insert(input[i]);
        for (auto it = previous.begin(); it != previous.end(); it++) {
            current.insert(gcd(input[i], *it));
        }
        for (auto it = current.begin(); it != current.end(); it++) {
            denominators.insert(*it);
        }
        previous = current;
    }

    cout << denominators.size() << endl;

    return 0;
}
