#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool palindrome(vector<int> &number) {
    for (int i = 0; i < number.size()/2; i++) {
        if (number[i] != number[(number.size() - 1) - i]) {
            return false;
        }
    }
    return true;
}

int log_b(double b, double n) {
    int size = 0;
    for (; n >= 1; n /= b) {
        size += 1;
    }
    return size;
}

vector<int> convert(int number, int base) {
    vector<int> arr(log_b(base, number));

    for (int i = 0; number > 0; i++) {
        int entry = number % base;
        number /= base;
        arr[(arr.size()-1)-i] = entry;
    }

    return arr;
}

int main() {

    int a, b, k;
    scanf("%d %d %d\n", &a, &b, &k);

    vector<int> set;
    for (int i = a; i <= b; i++) {
        set.push_back(i);
    }

    vector<int> bases(k+1);
    for (int i = 2; i <= k; i++) {
        vector<int> subset;
        for (int number : set) {
            vector<int> word = convert(number, i);
            if (palindrome(word)) {
                bases[i] += 1;
                subset.push_back(number);
            }
        }
        swap(set, subset);
    }

    printf("%d\n", bases[k]);

    return 0;
}

