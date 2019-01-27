#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> factored;
unordered_map<int, map<int, int>> factorization;

void factorize(int number, int denom) {

    if (factored[number]) return;

    bool prime = true;
    for (int i = denom; i <= sqrt(number); i++) {
        if (number % i == 0) {
            prime = false;
            if (!factored[number/i]) {
                factorize(number/i, i);
            }

            factorization[number] = factorization[number/i];
            factorization[number][i] += 1;

            break;
        }
    }

    if (prime) factorization[number] = {{ number, 1 }};
    factored[number] = true;

    return;
}

int main() {

    int number;
    vector<int> trace;
    vector<int> numbers;
    while(cin >> number) {
        numbers.push_back(number);
    }

    for (auto number : numbers) {
        factorize(abs(number), 2);
        if (number < 0) cout << "-1 ";
        for (auto factor : factorization[abs(number)]) {
            cout << factor.first;
            if (factor.second > 1) {
                cout << "^" << factor.second;
            }
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
