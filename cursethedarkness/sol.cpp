#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    string line;

    if (!cases) cout << "curse the darkness" << endl;

    for (int i = 0; i < cases; i++) {
        // Book point.
        double bx, by;
        cin >> bx >> by;

        int num_candles;
        cin >> num_candles;

        bool reachable = false;
        for (int j = 0; j < num_candles; j++) {
            double cx, cy;
            cin >> cx >> cy;
            // Can't break --- still have I/O.
            if (hypot(cx - bx, cy - by) <= 8.0) {
                reachable = true;
            }
        }

        if (reachable) {
            cout << "light a candle" << endl;
        } else {
            cout << "curse the darkness" << endl;
        }

    }

    return 0;
}
