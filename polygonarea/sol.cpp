#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int num;
    while (cin >> num) {

        if (!num)
            return 0;

        vector<pair<double, double>> input;
        // Calculate area by adding each individual triangle that is formed
        // withinthe polygon.
        for (int i = 0; i < num; i++) {
            double x, y;
            cin >> x >> y;
            input.push_back({x, y});
        }
        input.push_back(input[0]);

        double area = 0.0;
        pair<double, double> a, b;
        for (int i = 0; i < num; i++) {
            a = input[i];
            b = input[i + 1];
            area += (b.first - a.first) * (a.second + b.second);
        }

        if (area < 0) {
            cout << "CCW ";
        } else {
            cout << "CW ";
        }

        cout << setprecision(1) << fixed << abs(area)/2 << endl;
    }

    return 0;
}
