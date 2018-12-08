#include <vector>
#include <map>

using namespace std;

inline int similar(string &input) {

    for (int i = input.size(); i >= 1; i--) {
        map<string, int> items;
        for (int j = 0; j <= input.size() - i; j++) {
            items[input.substr(j, i)]++;
        }

        bool possible = true;
        for (auto item : items) {
           if (item.second < 2) {
               possible = false;
               break;
           }
        }

        if (possible) return i;
    }

    return 0;
}

int main() {

    string input;
    while (cin >> input) {
        cout << similar(input) << endl;
    }

    return 0;
}

