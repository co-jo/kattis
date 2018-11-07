#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (!b) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void parse(long long n, long long d, long long s) {
    bool neg = true;
    if (n < 0 && d < 0 || n > 0 && d > 0) {
        neg = false; 
    }

    n = abs(n)/s;
    d = abs(d)/s;

    if (!d) {
        cout << "0 / 1" << endl;
    } else {
        // Output appears to always expect the negative qualifier on the numerator.
        cout << (neg ? n * -1 : n) << " / " << d << endl;
    }
}

int main() {

    int num;
    cin >> num;

    char op;
    long long x1, y1, x2, y2;

    for (int i =  0; i < num; i++) {
        cin >> x1 >> y1 >> op >> x2 >> y2;

        //int a = gcd(x1, y1);
        //int b gcd(x2, y2);
        long long numerator;
        long long denominator;
        long long a = x1, b = y1, c = x2, d = y2;
        if (op == '+') {
            // Make common terms.
            a *= y2; b *= y2; c *= y1; d *= y1;
            // Add
            numerator = a + c;
            denominator = b;
            // Simplify.
            long long s = gcd(abs(numerator), abs(denominator));
            parse(numerator, denominator, s);
        } else if (op == '-') {
            // Make common terms.
            a *= y2; b *= y2; c *= y1; d *= y1;
            // Op
            numerator = a - c;
            denominator = b;
            // Simplify.
            long long s = gcd(abs(numerator), abs(denominator));
            parse(numerator, denominator, s);
        } else if (op == '/') {
            // Op
            numerator = x1 * y2;
            denominator = y1 * x2;
            // Simplify.
            long long s = gcd(abs(numerator), abs(denominator));
            parse(numerator, denominator, s);
        } else {
            // Op
            numerator = x1 * x2;
            denominator = y1 * y2;
            // Simplify.
            long long s = gcd(abs(numerator), abs(denominator));
            parse(numerator, denominator, s);
        }

    }

    return 0;
}
