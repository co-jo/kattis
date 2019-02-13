#include <iostream>

using namespace std;

int main() {

    int l = 1,  h = 1000;

    string response;
    for (int i = 1; i <= 10; i++) {

        int m = (h + l)/2;
        cout << m << endl;

        cin >> response;
        if (response == "lower") {
            h = m - 1;
        } else if (response == "higher") {
            l = m + 1;
        } else if (response == "correct") {
            break;
        }

    }

    return 0;
}
