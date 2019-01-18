#include <iostream>
#include <vector>
#include <string>

#define MAX 101

using namespace std;

int opts[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
string outcomes[] = { "NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY" };

int find(int state, int priest, vector<int> &preferences) {
    int choice = 0, preference = MAX;
    for (int bit = 0; bit <= 2; bit++) {
        int flipped = state ^ (1 << bit);
        if (preference > preferences[flipped]) {
            preference = preferences[flipped];
            choice = flipped;
        }

    }
    return choice;
}

int optimal(vector<int> choices, int start, vector<int> &preferences) {
    int choice = 0, preference = MAX;
    for (int i = 0; i <= 2; i++) {
        if (preference > preferences[choices[i]]) {
            preference = preferences[choices[i]];
            choice = choices[i];
        }
    }
    return choice;
}

int main() {

    int rounds, priests, preference;
    cin >> rounds;

    for (int i = 0; i < rounds; i++) {
        cin >> priests;
        vector<vector<int>> votes(priests);
        vector<vector<int>> table(priests, vector<int>(8, MAX));

        for (int j = 0; j < priests; j++) {
            for (int k = 0; k < 8; k++) {
                cin >> preference;
                votes[j].push_back(preference - 1);
            }
        }

        for (int j = 0; j < 8; j++) {
            table[priests - 1][j] = find(j, priests - 1, votes[priests - 1]);
        }

        for (int j = priests - 2; j >= 0; j--) {
            for (int k = 0; k < 8; k++) {
                vector<int> choices;
                for (int bit = 0; bit <= 2; bit++) {
                    choices.push_back(table[j + 1][k^(1 << bit)]);
                }
                table[j][k] = optimal(choices, k, votes[j]);
            }
        }

        cout << outcomes[table[0][0]] << endl;
    }

    return 0;
}

