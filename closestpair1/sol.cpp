#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
#include <iomanip>

// Arbitrary, substitute for INT_MAX, worried about overflow
#define MAX 500000
#define DEBUG 0

struct point {
    double x,y;
};

point first, second;
double minimum = INT_MAX;

using namespace std;

bool cmpx(point const &lhs,  point const &rhs) {
    return lhs.x < rhs.x;
}

double distance(point &a, point &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double recurse(point *sorted, point *aux, int low, int high) {

    if (high <= low) return INT_MAX;

    int mid = low + (high - low)/2;

    double left = recurse(sorted, aux, low, mid);
    double right = recurse(sorted, aux, mid + 1, high);

    double delta = min(left, right);

    int range = 0;
    for (int i = low; i <= high; i++) {
        if (abs(sorted[i].x - sorted[mid].x) < delta) {
            aux[range++] = sorted[i];
        }
    }

    for (int i = 0; i < range; i++) {
        for (int j = i + 1; j < range; j++) {
            double dist = distance(aux[j], aux[i]);
            if (dist < delta) {
                delta = dist;
                if (delta < minimum) {
                    minimum = delta;
                    first = aux[i];
                    second = aux[j];
                }
            }
        }
    }

    return delta;
}

double closest(point *inputs, point *aux, int num) {
    // We have to consider some mimimum distance d along both axis.
    sort(inputs, inputs + num, cmpx);

    return recurse(inputs, aux, 0, num - 1);
}

int main() {

    int num;

    point inputs [100000];
    point aux [100000];
    while(cin >> num) {
        if (!num) return 0;

        double x, y;
        for (int i = 0; i < num; i++) {
            cin >> x >> y;
            inputs[i] = {x, y};
        }

        double dist = closest(inputs, aux, num);

        cout << setprecision(2);
        cout << fixed << first.x << ' ' << first.y << ' ' << second.x << ' ' << second.y << endl;

        minimum = INT_MAX;
    }

    return 0;
}

