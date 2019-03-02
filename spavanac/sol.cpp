#include <iostream>

using namespace std;

int main() {

    int hour, min;
    cin >> hour >> min;

    if (min < 45) {
        min = 60 - (45 - min);
        hour = (!hour) ? 23 : hour - 1;
        cout << hour << ' ' << min;
    } else {
        cout << hour << ' ' << min - 45;
    }

    return 0;
}
