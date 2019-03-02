#include <iostream>
#include <bitset>

#define MAX 300

using namespace std;

int main() {

    int n;
    cin >> n;

    int ids[MAX];
    for (int i = 0; i < n; i++) {
        cin >> ids[i];
    }

    for (int i = 1; i <= 999999; i++) {
        bool valid = true;
        bitset<100000> mods;
        for (int j = 0; j < n; j++) {
            int m = ids[j] % i;
            if (mods[m]) {
                valid = false; break;
            } else {
                mods[m] = true;
            }
        }
        if (valid) {
            cout << i << endl; break;
        }
    }

    return 0;
}
