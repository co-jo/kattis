#include <iostream>
#include <vector>
#include <set>
#define TARGET 1000
#define LIMIT 1500


using namespace std;

int main() {
    int num_plates;
    cin >> num_plates;

    vector<int> plates;
    for (int i = 0; i < num_plates; i++) {
        int plate;
        cin >> plate;
        plates.push_back(plate);
    }

    // First approach was to take the 'more' optimal approach and have the sub-problem
    // represent the closest subset sum to any target weight. I could not work out
    // the kinks, so the current approach it to simiply solve the  subset sum problem,
    // insert the results into a set and find the upper_bound of 1000.
    set<int> results;
    vector<vector<bool>> matrix(num_plates + 1, vector<bool>(LIMIT + 1, 0));

    // Important: Subset automatically contains zero.
    for (int i = 0; i <= num_plates; i++)
        matrix[i][0] = true;

    for (int i = 1; i <= num_plates; i++) {
        for (int j = 1; j <= LIMIT; j++) {
            int weight = plates[i - 1];
            matrix[i][j] = matrix[i - 1][j];
            // Current weight it too large. Check if above forms subset of j.
            if (j >= weight) {
                matrix[i][j] = matrix[i][j] || matrix[i - 1][j - weight];
            }
        }
    }

    for (int i = 0; i <= LIMIT; i++)
        if (matrix[num_plates][i] && i != 0)
            results.insert(i);

    set<int>::iterator bound = results.lower_bound(TARGET);
    int upper = *bound;
    int lower = *prev(bound);

    // If the difference of the upper bound is less than or eq, use upper.
    if (abs(TARGET - upper) <= abs(TARGET - lower))
        cout << upper << endl;
    else
        cout << lower << endl;

    return 0;
}
