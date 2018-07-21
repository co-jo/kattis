#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

string bases = "0123456789abcdefghijklmnopqrstuvwxyz";

int min_base(string input) {
  int max = 0;
  bool zeroes = false;
  for (char &c : input) {
    int current = bases.find(c);
    if (current == 0) zeroes = true;
    max = (max < current) ? current : max;
  }
  return (max == 1 && !zeroes) ? max : max + 1;
}

int convert(string input, int base) {
  int sum = 0;
  int size = input.size();
  int pow = 1;
  // Integer
  for (int i = 0; i < size; i++) {
    int constant = bases.find(input[size - i - 1]);
    sum += constant * pow;
    pow *= base;
  }
  return sum;
}

bool compute(string a, string b, string res, int base, char op) {
  int first = convert(a, base);
  int second = convert(b, base);
  int result = convert(res, base);

  if (op == '+') return (first + second) == result;
  else if (op == '-') return (first - second) == result;
  else if (op == '*') return (first * second) == result;
  else if (op == '/') return first % second == 0 && first / second == result;

  return false;
}

int main() {
  int num;
  cin >> num;

  string expression[5];
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 5; j++)
      cin >> expression[j];

    // Try each base starting from min possible base.
    int base = min_base(expression[0] + expression[2] + expression[4]);
    char op = expression[1][0];
    string output = "";
    for (int i = base; i < 37; i++) {
      bool eq = compute(expression[0], expression[2], expression[4], i, op);
      if (eq) {
        if (i == 36) output += '0';
        else output += bases[i];
      }
    }

    if (output.empty())
      cout << "invalid" << endl;
    else
      cout << output << endl;
  }

  return 0;
}
