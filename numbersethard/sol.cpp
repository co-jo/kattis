#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

int find(long long x, vector<int> &link) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same (long long a, long long b, vector<int> &link) {
    return find(a, link) == find(b, link);
}

void unite(long long a, long long b, vector<int> &link, vector<int> &size) {
    int x = find(a, link);
    int y = find(b, link);
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    link[y] = x;
}

int main() {

    int cases;
    cin >> cases;

    vector<int> primes;
    int limit = 1000001;
    vector<bool> sieve(limit, 1);
    for (long long i = 2; i < limit; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < limit; j += i) {
                sieve[j] = 0;
            }
        }
    }

    long long lower, upper, prime;
    for (int i = 0; i < cases; i++) {
        vector<long long> range;
        cin >> lower >> upper >> prime;
        for (long long j = lower; j <= upper; j++) {
            range.push_back(j);
        }

        int sets = range.size();
        // Makeset.
        vector<int> link;
        vector<int> size(sets, 1);
        for (int i = 0; i < sets; i++) link.push_back(i);

        // First prime number in the range
        auto it = lower_bound(primes.begin(), primes.end(), prime);
        for (; it != primes.end() && *it < upper ; it++) {
            int start = ceil(double(lower)/double(*it)) * (*it) - lower;
            for (int j = start + *it; j < range.size(); j+=*it) {
                if (!same(start, j, link)) {
                    unite(start, j, link, size);
                    sets--;
                }
            }

        }
        cout << "Case #" << i + 1 << ": " << sets << endl;
    }

    return 0;
}
