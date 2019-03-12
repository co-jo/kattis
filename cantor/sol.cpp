#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

bool convert(float i) {
    int p = 0;
    double c = 0.0;
    for (int j = 1; j <= 12; j++) {
        p = i * 3.0;
        i = (i * 3.0) - p;
        c += p/pow(10.0, j);
        if (p == 1.0) return false;
    }
    return true;
}

int main() {

    float in;
    while (scanf("%f\n", &in)) {
        if (!convert(in)) {
            printf("NON-MEMBER\n");
        } else {
            printf("MEMBER\n");
        }
    }

    return 0;
}
