#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    while(a.size() != b.size()) {
        if (a.size() < b.size()) a = "0" + a;
        else b = "0" + b;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] - b[i] < 0) {
            a[i] = ' ';
        } else if (a[i] - b[i] > 0) {
            b[i] = ' ';
        }
    }

    string ra = "", rb = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ' ') ra += a[i];
        if (b[i] != ' ') rb += b[i];
    }

    if (ra.size() == 0) {
        cout << "YODA" << endl;
    }  else {
        cout << stoi(ra) << endl;
    }

    if (rb.size() == 0) {
        cout << "YODA" << endl;
    } else {
        cout << stoi(rb) << endl;
    }

    return 0;
}
