#include <iostream>

using namespace std;

int points(char d, char number, char suit) {
    if (number == 'A') return 11;
    if (number == 'K') return 4;
    if (number == 'Q') return 3;
    if (number == 'J') {
        return (suit == d) ? 20 : 2;
    }
    if (number == 'T') return 10;
    if (number == '9' && d == suit) return 14;
    return 0;
}

int main() {

    char d;
    int n, s = 0;
    scanf("%d %c\n", &n, &d);

    char suit, number;
    for (int i = 0; i < 4*n; i++) {
        scanf("%c%c\n", &number, &suit);
        s += points(d, number, suit);
    }
    printf("%d\n", s);

    return 0;
}
