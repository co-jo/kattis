#include <cmath>
#include <iostream>
#include <unordered_map>

#define MAX 100000

using namespace std;

inline int mod(int num) {
    return num % 1000;
}

unordered_map<int, bool> valid;
unordered_map<int, pair<double, double>> table;

pair<double, double> recurse(int factor) {

    if (valid[factor]) return table[factor];

    pair<double, double> left = recurse(floor(double(factor)/2.0));
    pair<double, double> right = recurse(ceil(double(factor)/2.0));

    double first = mod((left.first * right.first) + (5 * left.second * right.second));
    double second = mod((left.first * right.second) + (right.first * left.second));

    if (!valid[factor]) {
        valid[factor] = true;
        table[factor] = {first, second};
    }

    return table[factor];
}

int main() {
    int numbers;
    double number;
    cin >> numbers;

    valid[1] = true;
    table[1] = { 3, 1 };

    for (int i = 1; i <= numbers; i++) {
        cin >> number;
        pair<double, double> coefficients = recurse(number);
        int ans = coefficients.first * 2 - 1;
        ans %= 1000;

        string output = to_string(ans);
        int size = output.size();
        for (int j = 0; j < (3 - size); j++) {
            output = "0" + output;
        }

        cout << "Case #" << i << ": " << output << endl;
    }

}
