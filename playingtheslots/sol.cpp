#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

struct point {
    double x,y;
};


// Rotate a, w.r.t b.
point rotate(point a, point b, double angle) {
    double x = (a.x - b.x) * cos(angle) - (a.y - b.y) * sin(angle) + b.x;
    double y = (a.x - b.x) * sin(angle) + (a.y - b.y) * cos(angle) + b.y;
    return { x, y };
}

double angle(point a, point b) {
    return -atan((b.y - a.y)/(b.x - a.x));
}

// Finding the convex hull is the hard part -- because we are already given it,
// we can just bound the hull in a rectangle and take the min of the width/length.
// The rotation is to make the this construction simpler by having an edge always be
// parallel to the x-axis.
int main() {

    int num;
    cin >> num;

    double x,y;
    vector<point> points;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        points.push_back({x,y});
    }
    points.push_back(points[0]);

    double width = INT_MAX;
    for (int i = 0; i < points.size() - 1; i++) {
        double ang = angle(points[i], points[i+1]);
        // Rotate points.
        vector<point> rotated = { points[i] };
        for (int j = 0; j < points.size() - 1; j++) {
            if (j != i) {
                rotated.push_back(rotate(points[j], points[i], ang));
            }
        }

        double ymax = -INT_MAX, ymin = INT_MAX, xmax = -INT_MAX, xmin = INT_MAX;
        // Take the min of (max.x - min.x) and  (max.y - min.y)
        for (int j = 0; j < rotated.size(); j++) {
            xmin = min(rotated[j].x, xmin);
            xmax = max(rotated[j].x, xmax);
            ymin = min(rotated[j].y, ymin);
            ymax = max(rotated[j].y, ymax);
        }
        double local_min = min(xmax - xmin, ymax - ymin);
        width = min(width, local_min);
    }

    cout << fixed << setprecision(8) << width << endl;

    return 0;
}
