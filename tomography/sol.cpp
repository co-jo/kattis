#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int rows, columns;
    cin >> rows >> columns;

    vector<int> row(rows);
    vector<int> column(columns);

    int sum;
    for (int i = 0; i < row.size(); i++) {
        cin >> sum;
        row[i] = sum;
    }

    for (int i = 0; i < column.size(); i++) {
        cin >> sum;
        column[i] = sum;
    }

    sort(row.rbegin(), row.rend());
    sort(column.rbegin(), column.rend());

    bool possible = true;
    for (int i = 0; i < row.size(); i++) {
        sum = row[i];
        for (int j = 0; j < column.size(); j++) {
            if (column[j] > 0) {
                column[j]--;
                sum--;
            }
            if (!sum) break;
        }
        if (sum) {
            possible = false;
            break;
        }
        sort(column.rbegin(), column.rend());
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
