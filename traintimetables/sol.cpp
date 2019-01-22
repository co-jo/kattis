#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

#define END 2400

using namespace std;

int convert(string str, int processing) {
    str.erase(str.begin() + 2);

    int time = stoi(str);
    int minutes = time % 100;
    if (minutes + processing >= 60) {
        int overflow = (minutes + processing) % 60;
        time = (time - minutes) + 100 + overflow;
    } else {
        time += processing;
    }

    return time;
}

int main() {

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int trips[2];
        int turnaround;
        cin >> turnaround >> trips[0] >> trips[1];

        string departure, arrival;
        vector<vector<int>> station_one(END), station_two(END);
        // Arrival queues.
        unordered_map<int, int> arrival_one, arrival_two;

        for (int j = 0; j < trips[0]; j++) {
            cin >> departure >> arrival;
            int time = convert(arrival, turnaround);
            station_one[convert(departure, 0)].push_back(time);
        }

        for (int j = 0; j < trips[1]; j++) {
            cin >> departure >> arrival;
            int time = convert(arrival, turnaround);
            station_two[convert(departure, 0)].push_back(time);
        }

        int start[] =  { 0, 0 };
        int trains[] = { 0, 0 };

        // Faster to keep the times which we know an 'event' will occur in a set.
        for (int time = 0; time < END; time++) {
            // Checks for trains currently available.
            if (arrival_one[time]) trains[0] += arrival_one[time];
            if (arrival_two[time]) trains[1] += arrival_two[time];
            for (int arrival : station_one[time]) {
                if (!trains[0]) {
                    start[0] += 1;
                } else {
                    trains[0]--;
                }
                arrival_two[arrival]++;
            }
            for (int arrival: station_two[time]) {
                if (!trains[1]) {
                    start[1] += 1;
                } else {
                    trains[1]--;
                }
                arrival_one[arrival]++;
            }
        }
        cout << "Case #" << (i + 1) << ": " << start[0] << ' ' << start[1] << endl;
    }

    return 0;
}
