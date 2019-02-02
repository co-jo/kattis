#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    int students;
    while(cin >> students){
        if (!students) break;

        double cents, sum = 0.0;
        vector<double> costs(students, 0);
        for (int i = 0; i < students; i++) {
            cin >> cents;
            costs[i] = cents * 100.0;
            sum += costs[i];
        }

        int average = sum / students;

        sort(costs.begin(), costs.end());

        int owed, spent = 0;
        for (int i = 0; i < students; i++) {
            if (costs[i] > average) {
                owed = i; break;
            }
            spent += (average - costs[i]);
        }

        // Average leftover amount to those who spent more than the average.
        double leftovers = (sum - (students * average))/double(students - owed);
        // If the people with costs above the average, divert all the remaining money
        // to bring them within the 1 cent differential.
        if (leftovers > 1.0) spent += (leftovers - 1.0) * (students - owed);

        cout << fixed << setprecision(2);
        cout << "$" << spent/100.0 << endl;
    }

    return 0;
}
