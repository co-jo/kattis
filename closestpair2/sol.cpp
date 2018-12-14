#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <unordered_map>

struct point {
    double x,y;
};

point first, second;
double minimum = INT_MAX;

using namespace std;

unordered_map<int, bool> keys;

bool cmpx(point const &lhs,  point const &rhs) {
    return lhs.x < rhs.x;
}

bool cmpy(point const &lhs,  point const &rhs) {
    return lhs.y < rhs.y;
}

double distance(point &a, point &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double brute(point *sorted, int low, int high) {
    double dist = INT_MAX;
    for (int i = low; i <= high; i++)  {
        for (int j = i + 1; j <= high; j++) {
            dist = min(dist, distance(sorted[i], sorted[j]));
            if (dist < minimum) {
                minimum = dist;
                first = sorted[i];
                second = sorted[j];
            }
        }
    }
    return dist;
}

// We can consider the bounds of ysorted to be 0 ... (high - low) as
// we created a new array on each call, and aren't following the low ... high range
// as we are with xsorted
double recurse(point *xsorted, point *ysorted, int low, int high) {

    if (high - low <= 3) {
        return brute(xsorted, low, high);
    }

    int mid = low + (high - low)/2;

    // Pre-sort (linear time) based on the left/right paritioning around mid.
    point leftpart[mid - low + 1];
    point rightpart[high - mid + 1];

    int r = 0, l = 0;
    for (int i = 0; i <= high - low; i++) {
        if (ysorted[i].x < xsorted[mid].x && l < (mid - low)) {
            leftpart[l++] = ysorted[i];
        } else if (r < (high - mid)) {
            rightpart[r++] = ysorted[i];
        } else {
            leftpart[l++] = ysorted[i];
        }
    }

    // The higher bound is inclusvie, therefore leftpart should get i_mid
    double left = recurse(xsorted, leftpart, low, mid);
    double right = recurse(xsorted, rightpart, mid + 1, high);
    // ysorted is assumed to be sorted, so we are not required to preform a combine step.
    double delta = min(left, right);

    int range = 0;
    point aux[high - low + 1];
    for (int i = 0; i <= high - low; i++) {
        if (abs(ysorted[i].x - xsorted[mid].x) < delta) {
            aux[range++] = ysorted[i];
        }
    }

    for (int i = 0; i < range; i++) {
        for (int j = i + 1; j < range && abs(aux[j].y - aux[i].y) < delta; j++) {
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

double closest(point *inputs, point* ysorted, int num) {
    // We have to consider some mimimum distance d along both axis.
    sort(inputs, inputs + num, cmpx);
    sort(ysorted, ysorted + num, cmpy);
    return recurse(inputs, ysorted, 0, num - 1);
}

int main() {

    int num;

    point inputs [100000];
    point ysorted [100000];

    while(cin >> num) {
        if (!num) return 0;

        double x, y;
        for (int i = 0; i < num; i++) {
            cin >> x >> y;
            inputs[i] = {x, y};
            ysorted[i] = inputs[i];
        }

        double dist = closest(inputs, ysorted, num);

        cout << setprecision(5);
        cout << fixed << first.x << ' ' << first.y << ' ' << second.x << ' ' << second.y << endl;

        minimum = INT_MAX;
    }

    return 0;
}


