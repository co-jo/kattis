#include <iostream>
#include <vector>

using namespace std;

vector<long long> results;
// Offset by 1 to maintain necessary indexing relation.
vector<long long> fenwick(5000001, 0);

// Calcualte sum from 1 ... index - 1
inline long long sum(long long index) {
    long long current = 0;

    while(index > 0) {
        current += fenwick[index];
        index -= index &- index;
    }

    return current;
}

inline void add(long long val, long long index, int limit) {
    while (index <= limit) {
        fenwick[index] += val;
        index += index &- index;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length, queries;
    cin >> length >> queries;

    char op;
    long long index, value;
    for (int i = 0; i < queries; i++) {
        cin >> op >> index;
        // Query operation.
        if (op == '?') {
            results.push_back(sum(index));
        } else {
            cin >> value;
            add(value, index + 1, length);
        }
    }

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }

    return 0;
}
