#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstdio>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    int start, goal, agencies;
    for (int i = 1; i <= cases; i++) {
        cout << "Case " << i << endl;

        cin >> start >> goal >> agencies;

        string line;
        set<pair<int, string>> order;
        for (int j = 0;  j < agencies; j++) {
            // Eat newline.
            getchar();

            char agency[16];
            int unit, half, work = start, cost = 0;
            scanf("%[^:]: %d, %d", &agency, &unit, &half);

            while (work/2 >= goal) {
                double chunk = ceil(double(work)/2.0);
                if (double(half)/chunk > unit) break;
                work /= 2;
                cost += half;
            }

            cost += (work - goal) * unit;

            order.insert({ cost, string(agency) });
        }

        for (auto it = order.begin(); it != order.end(); it++) {
            cout << it->second << ' ' << it->first << endl;
        }
    }

    return 0;
}

