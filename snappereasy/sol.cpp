#include <iostream>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    int snappers, snaps;
    for (int i = 0; i < cases; i++) {
        cin >> snappers >> snaps;
        int ans = ((1 << snappers) - 1) & snaps;
        if (ans == ((1 << snappers) - 1)) {
            cout << "Case #" << (i + 1) << ": ON" << endl;
        } else {
            cout << "Case #" << (i + 1) << ": OFF" << endl;
        }
    }

    return 0;
}
