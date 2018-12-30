#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int years;
    cin >> years;

    double qaly = 0.0;
    double quality, duration;
    for (int i = 0; i < years; i++) {
        cin >> quality >> duration;
        qaly += (quality * duration);
    }

    cout << fixed << setprecision(3);
    cout << qaly << endl;

    return 0;
}
