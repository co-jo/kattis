#include<iostream>
#include<array>
#include<bitset>
#include<cmath>

using namespace std;

int main() {
  int ingredients;
  int pairs;
  cin >> ingredients >> pairs;

  array<bitset<20>, 400> invalid;
  for (int i = 0; i < pairs; i++) {
    int one, two;
    cin >> one >> two;
    invalid[i].set(one - 1);
    invalid[i].set(two - 1);
  }

  int count = 0;
  int max = pow(2, ingredients);
  for (int i = 0; i < 1 << ingredients; i++) {
    bitset<20> subset(i);
    for (int j = 0; j < pairs ; j++)
      if ((invalid[j] &~ subset) == 0) { count++; break; }
  }

  cout << (max - count) << endl;
  return 0;
}
