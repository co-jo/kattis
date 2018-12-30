#include <iostream>
#include <string>
#include <map>

using namespace std;

bool cmp(char a, char b) {
    if (a == '0') {
        return false;
    } else if (b == '0') {
        return true;
    } else {
        return a < b;
    }
}

int main() {
    string num;
    cin >> num;

    map<char, int> count = {
        {'1', 0},
        {'2', 0},
        {'3', 0},
        {'4', 0},
        {'5', 0},
        {'6', 0},
        {'7', 0},
        {'8', 0},
        {'9', 0},
        {'0', 0},
    };

    for (int i = 0; i < num.size(); i++) {
        count[num[i]]++;
    }

    char key = '0';
    int val = 10000;
    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second < val || it->second == val && cmp(it->first, key)) {
            key = it->first;
            val = it->second;
        }
    }

    if (key == '0') {
        cout << "1" + string(val + 1, '0') << endl;
    } else {
        cout << string(val + 1, key) << endl;
    }

    return 0;
}
