#include <iostream>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

int main() {

    long long input;
    cin >> input;

    map<int, int> digits;
    for (int i = 2; i <= sqrt(input) && input > 1; i++) {
        while (input % i == 0) {
            digits[i]++;
            input /= i;
        }
    }


    int val = 0, key = INT_MAX;
    for (auto it = digits.begin(); it != digits.end(); it++) {
        if (it->second > val || it->first < key && it->second == val) {
            val = it->second;
            key = it->first;
        }
    }

    if (!val) {
        cout << input << endl;
    } else {
        cout << key << endl;
    }

    return 0;
}
