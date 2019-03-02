#include <iostream>

using namespace std;

int main() {

    string input;
    cin >> input;

    if (input == "2") {
        cout << 2;
    } else if (input == "6") {
        cout << 3;
    } else {

        int l = 1;
        int n = input.size();
        double head = 1.0;

        for (int i = 1;;i++) {
            head *= i;
            while (head >= 10.0) {
                head /= 10;
                l += 1;
            }
            if (l == n) {
                cout << i; break;
            }
        }
    }

    return 0;
}
