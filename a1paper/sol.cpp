#include<iostream>
#include<vector>
#include <cmath>
#include<iomanip>

using namespace std;

int main() {
    int smallest, count;
    cin >> smallest;

    vector<double> counts = { 0 };
    while(cin >> count) {
        counts.push_back(count);
    }

    double width = pow(2, -1.25);
    double length = pow(2, -0.75);

    vector<double> costs(smallest, 0);
    for (int i = 1; i < smallest; i++) {
        // costs[i] = the amount of tape required to form type A{i}.
        if (i % 2) {
            costs[i] = length / (pow(2.0, double(i-1)/2.0));
        } else {
            costs[i] = width / (pow(2.0, double(i)/2.0 - 1));
        }
    }

    double tape = 0.0;
    bool possible = false;
    // More specifically, the pages needed for the next page size.
    double pages_needed = 1.0;
    // Take the larger pieces until we each the target area of an A1 piece.
    for (int i = 0; i < smallest; i++) {
        // Divide by two because we many need x pages, but tape two together.
        tape += costs[i] * (pages_needed/2);

        if (pages_needed <= counts[i]) {
            possible = true; break;
        } else {
            // Double the pages needed, minus the amount we currently have at this
            // curent size.
            pages_needed = 2.0 * (pages_needed - (counts[i]));
        }
    }

    if (possible) cout << fixed << setprecision(10) << tape << endl;
    else cout << "impossible" << endl;

    return 0;
}
