#include <iostream>
#include <string>

using namespace std;

char alpha[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

inline char rotate(int val, int ch) {
    return alpha[((ch - 'A') + val) % 26];
}

int main() {

    string line;
    cin >> line;

    // Divide.
    string first = line.substr(0, line.size()/2);
    string second = line.substr(line.size()/2, line.size() - 1);

    // Rotate Step.
    int first_sum = 0, second_sum = 0;
    for (int i = 0; i < first.size(); i++) {
        first_sum += (first[i] - 'A');
        second_sum += second[i] - 'A';
    }

    for (int i = 0; i < first.size(); i++) {
        first[i] = rotate(first[i], first_sum);
        second[i] = rotate(second[i], second_sum);
    }

    // Merge Step.
    for (int i = 0; i < first.size(); i++) {
        first[i] = rotate(first[i], second[i] - 'A');
    }

    cout << first << endl;

    return 0;
}
