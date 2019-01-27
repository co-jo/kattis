

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int num, nums;
    while (cin >> nums) {
        if (!nums) break;

        vector<int> numbers(nums, 0);
        vector<vector<int>> table(nums, vector<int>(nums, 0));
        for (int i = 0; i < nums; i++) {
            cin >> num;
            numbers[i] = num;
            table[i][i] = 1;
        }

        int length = 0;
        for (int i = 1; i < nums; i++) {
            for (int j = 0; j < i; j++) {
                table[i][j] = table[i - 1][j];
                if (numbers[i] > numbers[j]) {
                    table[i][i] = max(table[i][j] + 1, table[i][i]);
                }
            }
            length = max(length, table[i][i]);
        }

        string sequence = "";
        cout << length << ' ';
        for (int i = nums - 1; i >= 0; i--) {
            if (table[nums - 1][i] == length) {
                sequence = to_string(numbers[i]) + " " + sequence;
                length--;
            }
        }
        cout << sequence << endl;

    }
    return 0;
}
