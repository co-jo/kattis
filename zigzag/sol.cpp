#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

int main() {

    int k;
    cin >> k;

    vector<pair<int, char>> table(MAX, { 0, ' ' });

    table[0] = { -1, 'a' };
    for (int i = 0; i <= MAX; i += 1) {
        for (int k = 0; k <= 25; k++) {
            int val = i + abs(table[i].second - ('a' + k));
            if (val <= MAX && table[val].second == ' ') {
                table[val] = { i, 'a' + k };
            }
        }
    }

    string name = "";
    while (k >= 0) {
        name = table[k].second + name;
        k = table[k].first;
    }
    cout << name << endl;

    return 0;
}
