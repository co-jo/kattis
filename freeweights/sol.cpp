#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Slower than in-place, but easier.
bool remove(int n, vector<int> &w) {
    // Parse.
    vector<int> bot, top;
    int offset = w.size()/2;
    for (int i = 0; i < w.size()/2; i++) {
        if (w[i] > n) top.push_back(w[i]);
        if (w[i + offset] > n) bot.push_back(w[i + offset]);
    }
    // Verify.
    for (int i = 0; i < top.size(); i += 2) {
        if (top[i] != top[i + 1]) return false;
    }
    for (int i = 0; i < bot.size(); i += 2) {
        if (bot[i] != bot[i + 1]) return false;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<int> weights(2 * n);
    vector<int> tries = { 0 };
    unordered_map<int, bool> exists;
    for (int i = 0; i < 2 * n; i++) {
        cin >> weights[i];
        if (!exists[weights[i]]) {
            exists[weights[i]] = true;
            tries.push_back(weights[i]);
        }
    }
    sort(tries.begin(), tries.end());


    int l = 0, m;
    int h = tries.size() - 1;

    int ans = 0;
    while (l <= h) {
        m = (h - l)/2 + l;
        if (remove(tries[m], weights)) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << tries[ans] << endl;

    return 0;
}
