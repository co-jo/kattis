#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
#include<algorithm>
#include <vector>

using namespace std;

struct  Node {
  int id, rank;
  Node* parent;
  Node(int i, int r): id(i), rank(r) {}
  Node(): id(0), rank(0), parent(nullptr) {}
};

void insert_node(unordered_map<int, Node>& houses, int id) {
  if (houses.find(id) != houses.end()) return;
  houses[id] = Node(id, 0);
  houses[id].parent = &houses[id];
}

Node* find_node(unordered_map<int, Node>& houses, int id) {
  Node *current = &houses[id];
  while (current->id != current->parent->id) {
    current = current->parent;
  }
  return current;
}

void join(unordered_map<int, Node>& houses, int one, int two) {
  Node *first = find_node(houses, one);
  Node *second = find_node(houses, two);
  // The input won't have a loop.
  if (first == second) return;

  if (first->rank > second->rank) {
    second->parent = first;
  } else {
    first->parent = second;
    if (first->rank == second->rank) {
      second->rank++;
    }
  }
}

int main() {
  int nodes;
  int cables;
  cin >> nodes >> cables;

  unordered_map<int, Node> houses;
  for (int i = 1; i <= nodes; i++) {
    insert_node(houses, i);
  }

  for (int i = 0; i < cables; i++) {
    int first, second;
    cin >> first >> second;
    // Insert if D.N.E
    join(houses, first, second);
    // Add parent if D.N.E, remove child if exists.
  }

  // Entry never entered, whole graph disconnected.
  if (houses.find(1) == houses.end()) {
    for (int i = 2; i <= nodes; i++)
      cout << i << endl;
    return 0;
  }

  // Remove entry point into network.
  Node* entry = find_node(houses, 1);
  int connected = 0;
  for (int i = 1; i <= nodes; i++) {
    Node* top = find_node(houses, i);
    if (top->id == entry->id) {
      connected++;
      continue;
    }
    cout << i << endl;
  }

  if (connected == nodes) cout << "Connected" << endl;

  return 0;
}
