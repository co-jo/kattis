#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {

    int trees, sum, height;
    cin >> trees >> sum;

    // Insertion of 1000000 elements isn't ideal -- kinda slow. Probably
    // can just binary search over the array.
    map<int, int> tree;
    for (int i = 0; i < trees; i++) {
        cin >> height;
        tree[height] += 1;
    }

    int setting = 0;
    pair<int, int> head;
    for (auto it = tree.rbegin(); it != tree.rend();) {
        head = *it;
        if (++it != tree.rend()) {
            int cut = head.first - it->first;
            if (cut * head.second < sum) {
                sum -= (cut * head.second);
                tree[it->first] += head.second;
            } else {
                break;
            }
        }
    }

    if (sum > 0) setting = head.first - ceil(double(sum) / double(head.second));

    cout << setting << endl;

    return 0;
}
