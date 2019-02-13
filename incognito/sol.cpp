#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    int cases, attrs;
    string type;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> attrs;
        int res = 0;
        unordered_map<string, int> types;
        for (int j = 0; j < attrs; j++) {
            cin >> type >> type;
            types[type] += 1;
        }
        for (pair<string, int> style : types) {
            res *= (style.second + 1);
        }
        cout << res - 1 << endl;
    }
    return 0;
}
