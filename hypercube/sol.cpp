#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

long long index(bitset<60> code, int size) {

    bool flip = 0;
    long long high = pow(2, size) - 1;
    long long prev = -1, low = 0, mid = 0;

    for (int i = size - 1; i >= 0; i--) {
        // 1 is low, 0 is high.
        mid = (high + low)/2;
        if (prev == 1) flip = !flip;
        // Flip is set, 1 is now low.
        if ((flip && code[i]) || (!flip && !code[i])) {
            high = mid;
        } else if ((flip && !code[i]) || (!flip && code[i])){
            low = mid + 1;
        }
        prev = code[i];
    }

    return high;
}

int main() {

    int num;
    cin >> num;

    string start, end;
    cin >> start >> end;

    bitset<60> to(end);
    bitset<60> from(start);

    cout << index(to, num) - index(from, num) - 1<< endl;

    return 0;
}
