#include <iostream>
#include <set>

using namespace std;

bool palindrome(int start, int length, string &word) {
    for (int i = 0; i < length/2; i++) {
        if (word[start+i] != word[start+(length-1)-i]) {
            return false;
        }
    }
    return true;
}

int main() {

    string line;
    while(cin >> line) {
        set<string> substrings;
        for (int i = 0; i < line.size(); i++) {
            for (int j = 2; j <= line.size() - i; j++) {
                if (palindrome(i, j, line)) {
                    substrings.insert(line.substr(i, j));
                }
            }
        }
        for (string pal : substrings) {
            cout << pal << '\n';
        }
        cout << '\n';
    }

    return 0;
}

