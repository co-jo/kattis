#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int num;
    cin >> num;

    int cubes = floor(pow(num, 1.0/3.0));
    vector<int> cache;

    // Precaclute cubes.
    for (int i = 0; i <= cubes; i++) {
        cache.push_back(pow(i, 3));
    }


    unordered_map<int, int> sums;
    // Calculate all 2-Combinations using the cubes, then take the max.
    for (int i = 0; i <= cubes; i++) {
        for (int j = i + 1; j <= cubes; j++) {
            int key = cache[i] + cache[j];
            sums[key]++;
        }
    }

    while (sums[num] < 2 && num > 0) num--;

    if (num > 0) {
        cout << num << endl;
    } else {
        cout << "none" << endl;
    }

    return 0;
}
