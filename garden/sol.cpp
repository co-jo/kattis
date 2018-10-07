#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include<iomanip>

using namespace std;

// y=mx+b: calculate b, which will tell us the length of the tangent and adjenct
// edges, which we can use to calculate the midpoint of the wall.
pair<double, double> midway(pair<int, int> one, pair<int, int> two, double slope) {
    // X_1 == X_2 (m = inf)
    if (one.first == two.first) {
       return {double(one.first), 0.0};
    }
    // Y_1 == Y_2 (m = 0)
    else if (one.second == two.second) {
        return {0.0, double(one.second)};
    } else {
        double b = one.second - (slope * one.first);
        double x_mid = (-b)/(slope + 1.0/slope);
        double y_mid = slope * x_mid + b;
        return {x_mid, y_mid};
    }
    return {0, 0};
}

double coverable(pair<int, int> one, pair<int, int> two, double slope, double radius) {
    pair<double, double> mid = midway(one, two, slope);
    double height = hypot(abs(mid.first), abs(mid.second));

    double total = M_PI * pow(radius, 2);
    // Radius is smaller than closest point to wall, can create full circle.
    if (radius <= height) {
        return total;
    }
    // Line crosses origin, cuts space in half.
    else if (!abs(mid.first) && !abs(mid.second)) {
        return total / 2.0;
    }
    // There is limitations based on placement of wall.
    else {
        // Calculate adjacent edge. (radius >= height)
        double adj = sqrt(pow(radius, 2) - pow(height, 2));
        double angle = 2 * (asin(adj/radius)) * (180/M_PI);
        return total - ((total * (angle/360.0)) - (height * adj));
    }

    return 0;
}

// General premise is to find the area of the slice, and subtract the segment
// that is created by the wall.
int main() {
    int target_area, x1, y1, x2, y2;
    cin >> target_area >> x1 >> y1 >> x2 >> y2;

    pair<int, int> one = {x1, y1};
    pair<int, int> two = {x2, y2};
    // Calculate the radius of a circle (chain), then half to get the lower bound
    // of the minimal chain we woudouble need.

    // Maximum radius we can have to achieve this target area --- semi circle.
    double max_radius = ceil(sqrt(target_area * 2 / M_PI));
    // Smallest radius needed to achieve taret --- full circle.
    double min_radius = ceil(sqrt(target_area / M_PI));

    double slope = (double(y2 - y1)/double(x2 - x1));
    // Try each radius, and test if it hits the target area.
    for (int i = min_radius; i <= max_radius; i++) {
        double current_area = coverable(one, two, slope, double(i));
        if (current_area >= double(target_area)) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
