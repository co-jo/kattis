#include <iostream>

using namespace std;

int main() {

    string alpha = "  `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    string input;
    while (getline(cin, input)) {
        for (int i = 0; i < input.size(); i++) {
            for (int j = 1; j < alpha.size(); j++) {
                if (alpha[j] == input[i]) {
                    cout << alpha[j-1]; break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}

