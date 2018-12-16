#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct point {
    int x, y;

    // First sort by x, and then by y.
    bool operator <(const point &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator !=(const point &a) const {
        return x != a.x || y != a.y;
    }
};

int cross(point a, point b, point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

// Andrew's
vector<point> solve(vector<point> &points) {

    if (points.size() == 1) return points;

    vector<point> hull(2 * (points.size() - 1));

    int index = 0;
    // Minimum acceptable partition size for the lower half
    int bound = 2;
    // L -> R (Upper -- going clockwise)
    for (int i = 0; i < points.size(); i++) {
        while(index >= bound && cross(hull[index-1], points[i], hull[index-2]) <= 0) {
            index--;
        }
        if (points[i] != hull[index - 1]) hull[index++] = points[i];
    }

    // Minimum acceptable parition size for the upper half
    bound = index + 1;
    // R -> L (Lower -- going clockwise)
    for (int i = points.size() - 1; i > 0; i--) {
        while(index >= bound && cross(hull[index-1], points[i-1], hull[index-2]) <= 0) {
            index--;
        }
        hull[index++] = points[i-1];
    }

    // Removes all extra zeroes, and the last duplicated point the upper/lower halfs meet.
    hull.resize(index - 1);

    return hull;
}

int main() {

    int num;
    while(cin >> num) {

        if (!num) return 0;

        int x,y;
        vector<point> points, sorted;
        for (int i = 0; i < num; i++) {
            cin >> x >> y;
            points.push_back({x,y});
        }

        sort(points.begin(), points.end());
        vector<point> convex = solve(points);

        cout << convex.size() << endl;
        for (int i = 0; i < convex.size(); i++) {
            cout << convex[i].x << ' ' << convex[i].y << endl;
        }

    }
    return 0;
}
