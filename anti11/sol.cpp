#include <iostream>
#include <cmath>

#define LIMIT 10001

using namespace std;

int main() {

    int valid[LIMIT] = {1, 2, 3};

    for (int i = 2; i <= 10000; i++) {
        valid[i] = (valid[i - 1] + valid[i - 2]) % 100000007;
    }

    int num, cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> num;
        cout << valid[num] << endl;
    }

    return 0;
}

