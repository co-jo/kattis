#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

//vector<string> tokenize(string str, char delim){
//  string token;
//  vector<string> list;
//  istringstream iss(str);
//
//  while (getline(iss, token, delim))
//    list.push_back(token);
//
//  return list;
//}

class Node {
  public:
    int id;
    int cost;
    int rnk;
    Node* parent;
    static Node* find(int id);
    static Node* join(int x, int y);
    static void insert(int id, int cost);
    Node(int i, int c): id(i), cost(c), rnk(0) {}
    Node(): id(0), cost(0), rnk(0), parent(0) {}
};

array<Node, 10001> store;

void Node::insert(int id, int cost) {
  store[id] = Node(id, cost);
  store[id].parent = &store[id];
}

Node* Node::find(int id) {
  Node *current = &store[id];
  while (current->id != current->parent->id) {
    current = current->parent;
  }
  return current;
}

Node* Node::join(int a, int b) {
  Node *anode = find(a);
  Node *bnode = find(b);

  if (anode == bnode) return anode;

  if (anode->rnk > bnode->rnk) {
    bnode->parent = anode;
    anode->cost += bnode->cost;
    return anode;
  } else {
    anode->parent = bnode;
    if (anode->rnk == bnode->rnk) {
      bnode->rnk++;
    }
    bnode->cost += anode->cost;
    return bnode;
  }
}

int main() {
  string line;
  cin >> line;
  int people = stoi(line);
  cin >> line;
  int relationships = stoi(line);

  int impossible = 0;
  // Construct people data
  for (int i = 0; i < people; i++) {
    cin >> line;
    Node::insert(i, stoi(line));
  }

  // Construct graph;
  for (int i = 0; i < relationships; i++) {
    int person[2];
    for (int j = 0; j < 2; j++) {
      cin >> line;
      person[j] = stoi(line);
    }
    Node *root = Node::join(person[0], person[1]);
    if (root->cost != 0 && !impossible) {
      impossible++;
    } else if (root->cost == 0 && impossible) {
      impossible--;
    }
  }

  if (impossible) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
  }

  return 0  ;
}
