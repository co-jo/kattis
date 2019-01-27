#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;


long long swaps = 0;
vector<int> student;

// Likely better to do in place merge...
vector<int> merge(int left, int right) {

    if (left == right) {
        return { student[left] };
    } else {

        int divider = (right + left)/2;
        vector<int> lower = merge(left, divider);
        vector<int> higher = merge(divider + 1, right);
        lower.push_back(INT_MAX);
        higher.push_back(INT_MAX);

        vector<int> sorted;
        int tail = 0, head = 0;
        while (tail <= right && head <= right) {
            if (lower[tail] < higher[head]) {
                sorted.push_back(lower[tail++]);
            } else if (higher[head] < lower[tail]) {
                sorted.push_back(higher[head++]);
                swaps += ((lower.size() - 1) - tail);
            } else {
                break;
            }
        }

        return sorted;
    }

}

int main() {

    int students;
    cin >> students;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number;
    for (int i = 0; i < students; i++) {
        cin >> number;
        student.push_back(number);
    }

    vector<int> sorted = merge(0, students - 1);
    cout << swaps << endl;

    return 0;
}
