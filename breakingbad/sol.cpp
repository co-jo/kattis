#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

#define UNTOUCHED -1
#define BLUE 0
#define RED 1

using namespace std;

// RESULT = 0.19s
// Not particularily fast, but conceptually more straight forward. Probably can optimize
// further by avoiding using the string as the key for everything.

// BFS - Returns whether this particular component is bipartite.
// We will check the validity of the colouring before entering the function call.
bool search(int val, string item, set<string> &edges, map<string, set<string>> &graph,
            unordered_map<string, int> &state) {
    // We will use recursion so we must check if this item is already assigned a val.
    if (state[item] != val && state[item] != UNTOUCHED) {
        return false;
    }
    // We have already visited this item once, therefore do not iterate over edges.
    else if(state[item] == val && state[item] != UNTOUCHED) {
        return true;
    }

    // Finally set the colour.
    state[item] = val;
    for (string edge : edges) {
        if (!search(RED - val, edge, graph[edge], graph, state)) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_items, num_invalid;
    cin >> num_items;

    // Keep map of string -> indecies to avoid expensive string transport.
    // Maintain colour state.
    vector<string> items;
    unordered_map<string, int> state;
    map<string, set<string>> graph;

    for (int i = 0; i < num_items; i++) {
        string item;
        cin >> item;
        items.push_back(item);
        state[item] = UNTOUCHED;
    }

    cin >> num_invalid;
    // Marks all items walter/jessie is not allowed to recieve.
    bool impossible = false;
    for (int i = 0; i < num_invalid; i++) {
        string first, second;
        cin >> first >> second;
        // Any edge from one node to another represents an imcompatibility.
        graph[first].insert(second);
        // Edge is bidirectional.
        graph[second].insert(first);
    }

    // One small complication is the fact that we aren't necessarily given
    // a single graph with num_items nodes. If we come across something that is
    // untouched we can assume it has not been coloured, and thus is safe to assign
    // any arbitrary colour on the entry node to this particular graph.
    for (int i = 0; i < num_items; i++) {
        if (state[items[i]] == UNTOUCHED) {
            // Set first colour
            if(!search(BLUE, items[i], graph[items[i]], graph, state)) {
                impossible = true;
                break;
            }
        }
    }

    if (impossible) {
        cout << "impossible" << endl;
    } else{
        // No point in iterating over it once, then assigning items to their respective
        // containers, and then iterating it over again. Might as well just iterate
        // over the items array twice, and avoid the copy of the string.
        for (int i = 0; i < num_items; i++) {
            if (state[items[i]] == BLUE) cout << items[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < num_items; i++) {
            if (state[items[i]] == RED) cout << items[i] << ' ';
        }
        cout << endl;

    }

    return 0;
}
