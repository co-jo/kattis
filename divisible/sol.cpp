#include <iostream>
#include <vector>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int divisor, nums, num;
        cin >> divisor >> nums;

        vector<int> prefix(nums + 1, 0);
        for (int j = 1; j <= nums; j++) {
            cin >> num;
            prefix[j] = num;
        }

        // Construct the 'mod prefix' array.
        for (int j = 1; j < prefix.size(); j++) {
            prefix[j] = (prefix[j] + prefix[j-1]) % divisor;
        }

        int total = 0;
        // If any two prefixs of the array have the same modulus this tells us
        // that while the prefix(s) might not be divisible by our divisor, the
        // difference between those two prefixes would be, as the prefix sum is
        // only increasing  in nature.
        vector<int> divisors(divisor, 0);
        for (int j = 0; j <= nums; j++) {
            total += divisors[prefix[j]]++;
        }
        cout << total << endl;
    }

    return 0;
}
