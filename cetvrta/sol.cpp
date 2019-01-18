#include <iostream>
#include <map>

using namespace std;

int main() {

    int x, y;
    map<int, int> first, second;
    while (cin >> x && cin >> y) {
        first[x] += 1;
        second[y] += 1;
    }

    for (auto it = first.begin(); it != first.end(); it++) {
        if (it->second == 1) cout << it->first << ' ';
    }

    for (auto it = second.begin(); it != second.end(); it++) {
        if (it->second == 1) cout << it->first << ' ';
    }

    return 0;
}
