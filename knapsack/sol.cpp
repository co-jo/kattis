#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

void sequence(vector<int> &sol, vector<vector<int>> &table, vector<pair<int, int>> &costs, int col, int row) {
    // Starting at the greatest weight (right most), traverse the column until y_i > y_{i - 1}
    // The row is the index of the item used, subtract the weight and iterate starting at column
    // corresponding to that weight, and the next row up.
    for (int i = row; i > 0; i--) {
        if (table[col][i] > table[col][i - 1]) {
            sol.push_back(i - 1);
            return sequence(sol, table, costs, col - costs[i - 1].second, i - 1);
        }
    }
}

int main() {

    // Gather Inputs.
    string line;
    while(getline(cin, line)) {
        int num_objects;
        double cap;
        stringstream stream(line);
        stream >> cap >> num_objects;

        vector<pair<int, int>> costs;
        for (int i = 0; i < num_objects; i++) {
            getline(cin, line);
            int value, weight;
            stringstream pair(line);
            pair >> value >> weight;
            costs.push_back({value, weight});
        }

        // Because we are not allowed repition, we must keep track of not only the weights, but
        // our choices thus far. We can maintain an array W[0..C][0..j] which denotes the maximum
        // value for some capacity, considereing items 0 -> j_i.
        vector<vector<int>> weights((int)cap + 1, vector<int>(num_objects + 1, 0));
        // For each available object, 
        for (int i = 1; i <= num_objects; i++) {
            for (int w = 1; w <= cap; w++)  {
                int value, weight;
                tie(value, weight) = costs[i - 1];
                // Don't Include: Weight of item is greater.
                if (weight > w) {
                    weights[w][i] = weights[w][i - 1];
                } else {
                    // Max of including item vs. not including item.
                    weights[w][i] = max(weights[w][i - 1], weights[w - weight][i - 1] + value);
                }
            }
        }

        vector<int> solution;
        sequence(solution, weights, costs, cap, num_objects);

        int size = solution.size();
        // Be careful to regonize that the inputs only say some real number <= 2000.
        if (!size) {
            cout << 0 << endl;
        } else {
            cout << size << endl;
            for (int i = 0; i < size - 1; i++) cout << solution[i] << ' ';
            cout << solution[size - 1] << endl;
        }
    }

    return 0;
}
