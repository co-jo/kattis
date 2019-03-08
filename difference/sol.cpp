#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

// All the numbers we've seen.
bitset<200000000> seen;

int main() {

    int ap, m, index;
    cin >> ap >> m;

    int l = (ap == 1) ? 2 : 1;
    seen[ap] = 1;

    if (seen[m]) {
        cout << 1 << endl;
    } else {
        vector<int> seq = { ap };
        for (int i = 2; true; i++) {

            int an = l + ap;
            seen[an] = 1;

            for (int n : seq) {
                seen[an - n] = 1;
            }
            seq.push_back(an);

            for (int j = l + 1; true; j++) {
                if (!seen[j]) {
                    l = j; break;
                }
            }

            if (seen[m]) {
                cout << i << endl; break;
            }
            ap = an;
        }
    }
    return 0;
}
