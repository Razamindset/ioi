#include <iostream>
using namespace std;

int main() {
  string exp;
  cin >> exp;

  if (exp.length() <= 1) {
    cout << exp;
    return 0;
  }

  string new_exp;
  new_exp += exp[0];

  for (int i = 2; i < exp.length(); i += 2) {
  }
  return 0;
}