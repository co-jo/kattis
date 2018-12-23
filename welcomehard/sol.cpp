#include <iostream>
#include <string>
#include <vector>

using namespace std;

string phrase = "welcome to code jam";

// If we know what the optimal solution was for up to the previous positon
// in the input string, to compute the solution for the current position,
// we see if we can match the current position to one from the phrase.
string solve(string input) {

    int table[input.size() + 1][phrase.size() + 1] = {};


    if (input[0] == 'w') {
        table[0][0] = 1;
    }

    for (int i = 1; i < input.size(); i++) {
        for (int j = 0; j < phrase.size(); j++) {
            // We know that if we don't have a match, we will always have atleast
            // the number of sequences of the previous position from the input string.
            table[i][j] = table[i - 1][j];
            // If we get a match there are two cases to handle.
            if (input[i] == phrase[j]) {
                // Is it the start of a new word, an not an 'extension'?
                if (j == 0) {
                    table[i][j] += 1;
                }
                // Not a 'w', so in the previous position, what was the number of sequences
                // from 0 ... i, for the position that comes before j.
                else {
                    table[i][j] += table[i - 1][j - 1];
                }
                table[i][j] %= 10000;
            }
        }
    }

    string res = to_string(table[input.size() - 1][phrase.size() - 1]);
    
    while (res.size() < 4) {
        res = "0" + res;
    }

    return res;
}

int main() {

    int tests;
    cin >> tests;

    string blank;
    getline(cin, blank);

    for (int i = 0; i < tests; i++) {
        string input;
        getline(cin, input);

        cout << "Case #" << i + 1 << ": " << solve(input) << endl;
    }

    return 0;
}
