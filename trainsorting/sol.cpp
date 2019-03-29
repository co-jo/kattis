#include <iostream>

using namespace std;

int trains[2001];

int increase[2001];
int decrease[2001];

int main() {

    int n;
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d\n", &trains[i]);
        increase[i] = decrease[i] = 1;
    }

    int length = 0;
    // The longest increasing/decreasing subsequences, such that they
    // **start** on some i'th element.
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >=i+1; j--) {
            if (trains[i] > trains[j]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
            if (trains[i] < trains[j]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
        length = max(length, decrease[i] + increase[i] - 1);
    }
    printf("%d\n", length);

    return 0;
}

