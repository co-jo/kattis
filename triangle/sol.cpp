#include <iostream>

#define MAX 10000

using namespace std;

int iterations[MAX];

int main() {

    int iteration, digits = 1;
    double circ = 2.0;
    for (int i = 0; i < MAX; i++) {
        circ *= 3.0/2.0;
        if (circ >= 10) {
            circ /= 10.0;
            digits += 1;
        }
        iterations[i] = digits;
    }

    for (int i = 1; cin >> iteration; i++) {
        cout << "Case " << i << ": " << iterations[iteration] << endl;
    }

    return 0;
}
