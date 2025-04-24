#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string exp;
  cin >> exp;

  if (exp.length() <= 1) {
    cout << exp;
    return 0;
  }
  vector<int> numbers;

  for (char ch : exp) {
    if (ch == '+') {
      continue;
    }
    numbers.push_back(ch - '0');
  }

  sort(numbers.begin(), numbers.end());

  exp = "";

  for (int i = 0; i < numbers.size(); i++) {
    exp += numbers[i];
    if (i != numbers.size() - 1) {
      exp += "+";
    }
  }

  cout << exp;

  return 0;
}