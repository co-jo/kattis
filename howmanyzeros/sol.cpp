#include <iostream>
#include <string>

using namespace std;

long long zeros(long long num) {

    if (num < 0) return 0;
    // Lazy.
    string str = to_string(num);

    long long left = 10, amount = 1, middle = 1, right = 0;
    // Start at the right most digit.
    for (int i = str.size() - 1; i >= 1; i--) {
        int digit = str[i] - '0';

        long long cycle = num / (middle * 10);

        if (digit) {
            amount += (cycle * middle);
        } else {
            // Must reduce # intervals by 1, +1 for the digit itself,
            // and + num % middle for all values prefixed by this 0.
            amount += ((cycle - 1) * middle) + num % middle + 1;
        }

        middle *= 10;
    }

    return amount;
}

int main() {

    long long m, n;

    while(true) {
        cin >> n >> m;
        if (n < 0 || m < 0) break;

        // We are inclusive of n.
        cout << zeros(m) - zeros(n - 1) << endl;
    }

    return 0;
}
