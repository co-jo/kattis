#include <iostream>

using namespace std;

int main() {

    int w, s, c, k;
    scanf("%d %d %d %d\n", &w, &s, &c, &k);

    if (!k) {
        printf("NO\n");
    } else if(s == 0 || w + c == 0) {
        printf("YES\n");
    } else if (s < k || w + c < k) {
        printf("YES\n");
    } else if (s == k && w + c <= 2*k || w + c == k && s <= 2*k) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
