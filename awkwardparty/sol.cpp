#include <iostream>
#include <algorithm>
#include <unordered_map>

#define MAX 100000

using namespace std;

int main() {

    int people, language, awkwardness = MAX;
    cin >> people;

    unordered_map<int, int> placements;
    for (int i = 0; i < people; i++) {
        cin >> language;
        if (placements.find(language) == placements.end()) {
            placements[language] = i;
        } else {
            awkwardness = min(i - placements[language], awkwardness);
            placements[language] = i;
        }
    }

    if (placements.size() == people) {
        cout << people << endl;
    } else {
        cout << awkwardness << endl;
    }

    return 0;
}
