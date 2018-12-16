#include<iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    int score = 0;
    int divisor = 2;

    for (int x = 2; x*x <= num; x++) {
        while (num % x == 0) {
            score++;
            num /= x;
        }
    }

    if (num > 2) score++;

    cout << score << endl;

    return 0;
}
