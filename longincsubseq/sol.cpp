#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>

using namespace std;

// Binary-Search
int search(vector<int> &inputs, vector<int> &tails, int target, int length) {

    int right = length; int left = 0;
    int val = inputs[target];

    while (left <= right) {
        // Search lower.
        int mid = floor((left + right)/2);
        // Greatest tail end smaller than target.
        if (inputs[tails[mid]] > val && inputs[tails[mid - 1]] < val) {
            //cout << "val: " << val << "mid: " << inputs[tails[mid]] << endl;
            //cout << mid << endl;
            return mid;
        }
        if (inputs[tails[mid]] > val)
            right = mid - 1;
        else if (inputs[tails[mid]] <= val)
            left = mid + 1;
    }

    return target;
}

int main() {
    int num;
    while(cin >> num) {
        vector<int> inputs;
        for (int i = 0; i < num; i++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }

        // Maintains a list of indicies that keep track of the heads for the length
        // of a sequence i, at each i'th position in the array.
        vector<int> tails(num, 0);
        // Maintains a list of indicies, such that the i'th index points to the value
        // preceeding the i'th element in the input array for some subseq.
        vector<int> prevs(num, -1);
        // The length of the current longest subseq.
        int length = 1;

        tails[0] = 0;
        for (int i = 1; i < num; i++) {
            // Case 1: Element is smaller than any head.
            if (inputs[i] < inputs[tails[0]]) {
                tails[0] = i;
            }
            // Case 2: Element is larger than any head, append to longest list.
            else if (inputs[i] > inputs[tails[length - 1]]) {
                prevs[i] = tails[length - 1];
                tails[length++] = i;
            }
            // Case 3: Niether, find list with head that is closest, but still smaller.
            // This is were the required log*n term comes in, we binary search over the list
            // of heads for each subsequence at length i. We want to find the longest subseq
            // such that inputs[i] is still greater than, the tail.
            else {
                int pos = search(inputs, tails, i, length);
                prevs[i] = tails[pos - 1];
                tails[pos] = i;
            }
        }


        vector<int> outputs;
        for (int i = tails[length - 1]; i >= 0; i = prevs[i]) {
            outputs.push_back(i);
        }

        cout << length << endl;
        for (int i = outputs.size() - 1; i >= 0; i--) cout << outputs[i] << ' ';
        cout << endl;
    }
    return 0;
}

