#include <iostream>
#include <cmath>

using namespace std;

int sum(int num) {
    int divisors = 1;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            divisors += i;
            if (i != num/i) {
                divisors += num/i;
            }
        }
    }

    return divisors;
}

int main() {

    int num;

    while (cin >> num) {
        if (sum(num) == num) {
            cout << num << " perfect" << endl;
        } else if (abs(sum(num) - num) <= 2) {
            cout << num << " almost perfect" << endl;
        } else {
            cout << num << " not perfect" << endl;
        }
    }

    return 0;
}
