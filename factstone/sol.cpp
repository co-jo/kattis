#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main() {

    map<double, int> factorial = {
        { log2(6), 3 }
    };

    double prev = log2(6);
    for (int i = 4; prev <= (1 << 22); i++) {
        prev += log2(i);
        if (prev >= pow(2, factorial.size())) {
            factorial[prev] = i;
        }
    }

    int year;
    while(cin >> year) {
        if (!year) return 0;
        int growth = ((year - (year % 10)) - 1960)/10 + 2;
        cout << (factorial.upper_bound(pow(2, growth)))->second - 1 << endl;
    }

    return 0;
}
