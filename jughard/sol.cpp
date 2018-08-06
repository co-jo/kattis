#include <iostream>

using namespace std;

int gcd(int a , int b) {
   if(!b) return a;
   a %= b;
   return gcd(b,a);
}

int main() {
  int num;
  cin >> num;

  for (int i = 0; i < num; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    if(d % gcd(a, b) == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
