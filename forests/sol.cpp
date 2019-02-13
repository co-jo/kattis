#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main() {
    int t, p, person, tree;
    cin >> p >> t;

    vector<bool> removed(201, false);
    vector<set<int>> opinion(p + 1);
    while(cin >> person  >> tree) {
        opinion[person].insert(tree);
    }

    int opinions = 0;
    for (int i = 1; i <= p; i++) {
        if (removed[i]) continue;
        for (int j =  i; j <= p; j++) {
            if (!removed[j] && opinion[i] == opinion[j]) {
                removed[j] = true;
            }
        }
        opinions += 1;
    }
    cout << opinions << endl;
}
