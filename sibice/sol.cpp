#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n, w, h, l;
    cin >> n >> w >> h;

    for (int i = 0; i < n; i++) {
       cin >> l;
       if (hypot(h,w) < l) {
           cout << "NE" << endl;
       } else {
           cout << "DA" << endl;
       }
    }

    return 0;
}
