#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {

    int n, q;
    cin >> n >> q;

    int a, b;
    vector<int> unit(n + 1);
    vector<int> base(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        base[i] = a;
        unit[i] = b - a;
    }


    long long x, y, v;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> v;
        long long s = v - base[x];

        long long n = (s  * unit[y]);
        long long d = (unit[x]);

        long long r = base[y];

        long long g = gcd(n,d);
      
        long long upper = (n/g + ((d/g) * r));
        long long lower = d/g;

        if (!upper) {
            cout << "0/1" << endl;
        } else if (upper < 0 && lower < 0) {
            cout <<  abs(upper) << "/" << abs(lower) << endl;
        } else if (upper < 0 || lower < 0) {
            cout << -1 * abs(upper) << "/" << abs(lower) << endl;
        } else {
            cout << upper << "/" << lower << endl;
        }

    }

    return 0;
}

