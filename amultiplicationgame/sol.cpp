#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    double input;

    while(cin >> input) {
        int i = 1;
        for (; input > 1.0; i++) {
            if (i % 2) {
                input /= 9.0;
            } else {
                input /= 2.0;
            }
        }
        if (i % 2) {
            cout << "Ollie wins." << endl;
        } else {
            cout << "Stan wins." << endl;
        }
    }

    return 0;
}
