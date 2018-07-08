#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct cmp {
  bool operator () (const pair<char, int> &lhs, const pair<char, int> &rhs) {
    return lhs.second < rhs.second;
  }
};

int perform(int a, int b, char op) {
  int result;
  switch(op) {
    case '/' : result = a/b; break;
    case '*' : result = a*b; break;
    case '+' : result = a+b; break;
    case '-' : result = a-b; break;
  }
  return result;
}

int eval(string expression, list<pair<char, int>> ops) {
  list<pair<char, int>> order = ops;
  order.sort(cmp());
  
  list<int> fours ({ 4, 4, 4, 4 });
  for (auto ele: order) {
    // Find pos of first operator
    char op = ele.first;
    int offset = 0;
    // Find index of element in sequence, and return iterator to remove.
    for (auto it = ops.begin(); it != ops.end(); ++it) {
      if (it->first == op) {
        ops.erase(it);
        break;
      }
      offset++;
    }
    // Update;
    auto lhs = next(fours.begin(), offset);
    auto rhs = next(lhs, 1);
    *lhs = perform(*lhs, *rhs, op);
    // Remove operator and operand.
    fours.erase(rhs);
  }

  return fours.front();
}

void remove(list<pair<char,int>> &ops, char op, int index) {
  int i = 0;
  for (auto it = ops.begin(); it != ops.end(); ++it) {
    if (op == it->first && i == index) {
      ops.erase(it);
      return;
    }
    i++;
  }
}

void insert(list<pair<char,int>> &ops, char op) {
  switch(op) {
    case '/' : ops.push_back(make_pair(op, 0)); break;
    case '*' : ops.push_back(make_pair(op, 1)); break;
    case '+' : ops.push_back(make_pair(op, 2)); break;
    case '-' : ops.push_back(make_pair(op, 3)); break;
  }
}

int main() {

  string line;
  getline(cin, line);
  int lines = stoi(line);

  unordered_map<int, string> results;
  list<pair<char,int>> ops;

  char operators[4] = { '*', '/', '+', '-' };
  string expression = "4 # 4 # 4 # 4";

  // Generate
  for (char op : operators) {
    expression[2] = op;
    insert(ops, op);
    for (char op : operators) {
      expression[6] = op;
      insert(ops, op);
      for (char op : operators) {
        expression[10] = op;
        insert(ops, op);
        int key = eval(expression, ops);
        results[key] = expression;
        remove(ops, op, 2);
      }
      remove(ops, op, 1);
    }
    remove(ops, op, 0);
  }

  // Loopup
  for (int i = 0; i < lines; i++) {
    string input;
    cin >> input;
    int key = stoi(input);
    string expression = results[key];
    if (expression.empty() || key < -60 || key > 256)
      cout << "no solution" << endl;
    else
      cout << expression << " = " << input << endl;
  }


  return 0;
}
