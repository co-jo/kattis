#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int num;
  int count = 0;
  cin >> num;
  stack<int> socks;
  socks.push(-1);

  //cout << socks.top() << endl;
  for (int i = 0; i < 2*num; i++) {
      int sock;
      int top = socks.top();
      cin >> sock;

      if (top == sock) {
        socks.pop();
        count++;
      } else {
        socks.push(sock);
      }
  }

  if (count == 0 || socks.size() != 1) {
    cout << "impossible" << endl;
  } else {
    cout << 2 * count << endl;
  }

  return 0;
}
