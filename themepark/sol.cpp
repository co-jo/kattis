#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rides, cart, groups;
    for (int i = 0; i < cases; i++) {
        cin >> rides >> cart >> groups;

        vector<long long> group(groups);
        for (int j = 0; j < groups; j++) {
            cin >> group[j];
        }
        for (int j = 0; j < groups - 1; j++) {
            group.push_back(group[j]);
        }

        long long end = 0;
        long long sum = group[end];
        // Given that we start with group j, what is the number of people we can fit on.
        vector<long long> ranges(groups), after(groups);
        for (int j = 0; j < groups; j++) {
            while(end < (j + groups - 1) && sum + group[end + 1] <= cart) {
                sum += group[end + 1];
                end += 1;
            }
            ranges[j] = sum;
            after[j] = (end + 1) % groups;
            sum -= group[j];
        }

        deque<int> trace;
        vector<int> visited(groups, 0);
        long long revenue = 0, start = 0;
        // Looks for a cycle.
        for (int j = 0; j < rides && !visited[start]; j++) {
            visited[start] = true;
            trace.push_back(start);
            revenue += ranges[start];
            start = after[start];
        }

        int left = rides - trace.size();
        if (left) {
            long long cycle = 0;
            // Removes previous groups leading up to the start of the cycle;
            for (int group : trace) {
                if (group != start) trace.pop_front();
                else break;
            }
            // Weight of the cycle;
            for (int group : trace) cycle += ranges[group];

            long long rem = left % trace.size();
            revenue += ((left - rem)/trace.size()) * cycle;

            // Catch any cycle that can only partially complete.
            for (int j = 0; j < rem; j++) {
                revenue += ranges[trace.at(j)];
            }
        }

        cout << "Case #" << (i + 1) << ": " << revenue << '\n';
    }

    return 0;
}
