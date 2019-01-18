#include <iostream>
#include <cmath>
#include <algorithm>

#define DEBUG 0

using namespace std;

int main() {

    long long sum = 0;
    long long magic = 1000000007;
    int length, width, height;
    cin >> length >> width >> height;

    int table[length + 1] = { 1 };

    // If we have enough ribbon to fill the frame, it is simply (h + 1)^w.
    if (length >= height * width) {
        sum = 1;
        for (int i = 0; i < width; i++) {
            sum = ((height + 1) * sum) % magic;
        }
        cout << sum - min(height + 1, length/width+ 1) << endl;
        return 0;
    }

    // table[n] represents the number of solutions for using a ribbon of length n.
    for (int i = 1; i <= width; i++) {
        for (int j = length; j >= 0; j--) {
            for (int k = 1; k <= height && j - k >= 0; k++) {
                table[j] = (table[j] + table[j - k]) % magic;
            }
        }
    }

    if (DEBUG) {
        for (int i = 0; i <= length; i++) {
            cout << table[i] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i <= length; i++) {
        sum = (sum + table[i]) % magic;
    }

    // We notice that height + 1 does not suffice for the second input, as the only count
    // a equal ribbon height that can fill the full frame, i.e there is a max ribbon height of 3, meaning
    // 4 total plain scenes, versues 6.
    cout << sum - min(height + 1, length/width+ 1) << endl;

    return 0;
}
