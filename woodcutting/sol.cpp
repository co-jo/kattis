#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int cases, customers, boards, length;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> customers;

        vector<double> lengths;
        for (int j = 0; j < customers; j++) {
            cin >> boards;
            double sum = 0.0;
            for (int k = 0; k < boards; k++) {
                cin >> length;
                sum += length;
            }
            lengths.push_back(sum);
        }

        sort(lengths.begin(), lengths.end());

        double total = 0.0;
        for (int j = 0; j < customers; j++) {
            total += (lengths[j] * (customers - j));
        }

        cout << fixed; cout.precision(6);
        cout << total / customers << endl;
    }

    return 0;
}
