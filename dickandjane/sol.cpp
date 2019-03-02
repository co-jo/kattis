#include <iostream>

using namespace std;

int main() {

    int  s, p, y, j;
    while (cin >> s >> p >> y >> j) {

        int r = (12 + j) - (p + y);
        int spot = y + r/3;
        int puff = p + r/3;
        int yertle = r/3;

        r %= 3;
        // If spot 'aged' faster since yertle was born, any unaccounted years
        // that are left (1 || 2), must first be added to puff first.
        if ((y - s) > p && r) {
            puff += 1;
            r--;
        }
        // Spot was born first, so he gets priority for unaccouted years.
        if (r) {
            spot += 1; r--;
        }
        if (r) puff += 1;

        cout << spot << ' ' << puff << ' ' << yertle << endl;
    }

    return 0;
}
