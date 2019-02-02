#include <iostream>
#include <vector>
#include <cmath>

#define MAX 2000001

using namespace std;

int main() {

    vector<int> factors(MAX, 0);
    for (int i = 1; i <= sqrt(MAX); i++) {
        for (int j = i; j <= MAX; j += i) {
            if (i == j) {
                factors[j] += 1; continue;
            }
            if (j/i > sqrt(MAX)) {
                factors[j] += 2;
            } else {
                factors[j] += 1;
            }
        }
    }

    vector<int> primes(MAX, 0);
    for (int i = 2; i <= MAX; i++) {
        if (factors[i] == 2) {
            for (int j = i; j <= MAX; j += i) {
                primes[j] += 1;
            }
        }
    }


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries, query;
    cin >> queries;
    for (int i = 0; i < queries; i++){
        cin >> query;
        cout << factors[query] - primes[query] << '\n';
    }

    return 0;
}
