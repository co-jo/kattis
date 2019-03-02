#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

int sizes[1001];
int link[1001];

using namespace std;

typedef pair<double, double> point;
typedef tuple<int, int, double> line;

bool cmp(const line lhs, const line rhs) {
    return get<2>(lhs) < get<2>(rhs);
}

int find(int p) {
    while (p != link[p]) p = link[p];
    return p;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    link[b] = a;
}

int main() {

    int n, p;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("\n");
        cin >> p;

        double x, y;
        vector<point> pts;
        for (int j = 0; j < p; j++) {
            scanf("%lf %lf", &x, &y);
            pts.push_back({x, y});
        }

        vector<line> lines;
        for (int j = 0; j < p; j++) {
            for (int k = j + 1; k < p; k++) {
                double d = hypot(pts[j].first - pts[k].first, pts[j].second - pts[k].second);
                lines.push_back({j, k, d});
            }
        }

        sort(lines.begin(), lines.end(), cmp);

        for (int j = 0; j <= 1000; j++) link[j] = j;
        for (int j = 0; j <= 1000; j++) sizes[j] = 1;

        double d = 0.0;
        for (int j = 0; j < lines.size() - 1; j++) {
            if (!same(get<0>(lines[j]), get<1>(lines[j]))) {
                d += get<2>(lines[j]);
                unite(get<0>(lines[j]), get<1>(lines[j]));
            }
        }

        printf("%.2f\n", d);
    }

    return 0;
}
