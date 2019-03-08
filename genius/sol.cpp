#include <iostream>

using namespace std;

int guess[101];
double weights[101][4];
double prob[101][4];
double wins[101][4];
double table[101][101] = { 1.0 };

int main() {

    int k, t, p, q;
    cin >> k >> t >> p >> q >> guess[0];

    for (int i = 1;  i < t; i++) {
        guess[i] = (guess[i-1] * p) % q;
    }

    for(int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> weights[i][j];
        }
        guess[i] %= 4;
    }


    for (int i = 0; i < t; i++) {
        // First
        for (int j = 0; j < 4; j += 2) {
            prob[i][j] = weights[i][j] / (weights[i][j] + weights[i][j+1]);
            prob[i][j + 1] = weights[i][j+1] / (weights[i][j] + weights[i][j+1]);
        }
        // Second
        for (int j = 0; j < 2; j++) {
            double one = prob[i][j] * prob[i][2] * (weights[i][j] / (weights[i][j] + weights[i][2]));
            double two = prob[i][j] * prob[i][3] * (weights[i][j] / ( weights[i][j] + weights[i][3]));
            wins[i][j] = one + two;
        }
        for (int j = 2; j < 4; j++) {
            double one = prob[i][j] * prob[i][0] * (weights[i][j] / (weights[i][j] + weights[i][0]));
            double two = prob[i][j] * prob[i][1] * (weights[i][j] / (weights[i][j] + weights[i][1]));
            wins[i][j] = one + two;
        }
    }

    // No successes.
    for (int i = 0; i < t; i++) {
        table[i+1][0] = table[i][0] * (1 - wins[i][guess[i]]);
    }

    // The probability of having j successes up to the i'th row.
    for (int i = 1 ; i <= t; i++) {
        for (int j = 1; j <= i; j++) {
            // No success -- still have j successes.
            table[i][j] = table[i-1][j] * (1 - wins[i-1][guess[i-1]]);
            // Success -- taken from j-1 successes from previous round.
            table[i][j] += table[i-1][j-1] * wins[i-1][guess[i-1]];
        }
    }


    double probability = 0.0;
    for (int i = k; i <= t; i++) {
        probability += table[t][i];
    }

    printf("%.10lf", probability);

    return 0;
}
