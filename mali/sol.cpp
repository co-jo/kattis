#include <iostream>
#include <vector>
#include <algorithm>

#define limit 101

using namespace std;

int position(int num, vector<int> &set) {
    int index = 1;
    for (int i = 1; i < num; i++) {
        index += set[i];
    }
    return index;
}

int value(int position, vector<int> &set) {
    int sum = 0, val = 0;
    for (int i = 1; sum < position; i++) {
        sum += set[i];
        val = limit - i;
    }
    return val;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rounds;
    cin >> rounds;

    vector<int> left(limit, 0);
    vector<int> right(limit, 0);

    int a, b;
    for (int i = 0; i < rounds; i++) {
        cin >> a >> b;

        left[a]++;
        right[abs(b - limit)]++;

        int ans = 0;
        for (int j = 1; j <= 100; j++) {
            if (!left[j]) continue;
            int pos = position(j, left);
            int val = value(pos, right);
            ans = max(ans, j + val);
        }
        cout << ans << '\n';
    }

    return 0;
}
