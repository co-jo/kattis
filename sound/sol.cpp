#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

void erase(multiset<int> &used, int key) {
    auto it = used.find(key);
    if (it != used.end()) {
        used.erase(it);
    }
}

// Pretty much standard sliding window problem, use ordered data-structure
// to maintain high and low bounds of the window.
int main() {
    int size, length, limit;
    cin >> size >> length >> limit;

    int sample;
    vector<int> samples;
    for (int i = 0; i < size; i++) {
        cin >> sample;
        samples.push_back(sample);
    }

    // Keeps account of the window
    deque<int> range;
    // Helps with I/O, and validity check
    vector<int> sequence;
    // Used to keep track of our high and low values.
    multiset<int> used;

    for (int i = 0; i < size; i++) {
        used.insert(samples[i]);
        range.push_back(samples[i]);
        while (*used.rbegin() - *used.begin() > limit) {
            erase(used, range.front());
            range.pop_front();
        }
        if (range.size() >= length) {
            sequence.push_back(i - length + 2);
        }
    }

    if (!sequence.size()) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < sequence.size(); i++) {
            cout << sequence[i] << endl;
        }
    }

    return 0;
}

