#include <iostream>
#include <map>

using namespace std;

int main() {

    string tree;
    map<string, int> trees;

    int total = 0;
    while(getline(cin, tree)) {
        trees[tree] += 1;
        total += 1;
    }

    cout.precision(8);
    for (pair<string, int> ele: trees) {
        cout << ele.first << ' ' << float(ele.second)*100.0/float(total) << endl;
    }
}
