#include <iostream>

using namespace std;

int main() {

    int num, set, _;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> _ >> set;
        int sum = set * (set + 1)/2;
        cout << i + 1 << ' ' << sum << ' ' << sum * 2 - set << ' ' << sum * 2 << endl;
    }

    return 0;
}
