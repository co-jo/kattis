#include <iostream>

using namespace std;

int main() {

    int n, p, s;
    cin >> n >> p;

    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        total += s;
    }

    // Note the 'strictly' constraint.
    if (p == 100) {
        cout << "impossible" << endl;
    } else  {
       for (int i = 0; true; i++) {
           int d = (p * (n + i) - total);
           if (d <= i * 100) {
               cout << i << endl; break;
           }
       }
    }

    return 0;
}
