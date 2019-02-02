#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// We test the distance from being a palindrome, starting at pos 'start'.
// It is assumed if we are starting at 'start', we must make atleast that many edits.
int distance(int start, string word) {
    int edits = start;
    int tail = word.size() - 1;
    for (int head = start; head < tail; head++) {
        if (word[head] != word[tail]) {
            edits += 1;
        }
        tail -= 1;
    }
    return edits;
}

int main() {

    string name;
    cin >> name;

    int edits = name.size();
    for (int i = 0; i < name.size(); i++) {
        int current = distance(i, name);
        edits = min(edits, current);
    }
    cout << edits << endl;

    return 0;
}
