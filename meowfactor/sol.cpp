#include <iostream>

using namespace std;

int main() {

    long long input;
    cin >> input;

    for (int i = 127; i > 0; i--) {
        int j = 0;
        long long result = input;
        for (; j < 9; j++) {
            if (result % i != 0) {
                break;
            }
            result /= i;
        }
        if (j == 9) {
            cout << i << endl; break;
        }
    }

    return 0;
}

