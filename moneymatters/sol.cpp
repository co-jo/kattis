#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> tokenize(string str, char delim){
    string token;
    vector<string> list; 
    istringstream iss(str);

    while (getline(iss, token, delim))
      list.push_back(token);

    return list;
}

class Node {
  public:
    int cost;
    int id;
    Node parent;
  Node(int c, int i, Node p):
    cost(c), id(i), parent(p)
  {}
};

// Union/Insert

class Graph {

}

int main() {
  string line;
  getline(cin, line);
  
  vector<string> tokens = tokenize(line, ' ');
 
  for (auto & str : tokens)
   cout << str << endl; 

  return 0  ;
}
