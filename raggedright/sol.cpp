#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {

    string line;
    int max_length = 0;
    int raggedness = 0;
    vector<int> lengths;
    while(getline(cin, line)) {
        int size = line.size();
        lengths.push_back(size);
        max_length = max(max_length, size);
    }

    for (int i = 0; i < lengths.size() - 1; i++) {
        raggedness += pow((max_length - lengths[i]), 2);
    }

    cout << raggedness << endl;
    return 0;
}
