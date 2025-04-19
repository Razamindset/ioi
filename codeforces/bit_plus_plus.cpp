#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string expression;
  int x;
  x = 0;

  while (n--) {
    cin >> expression;

    if (expression.find("++") != -1) {
      x++;
    }
    if (expression.find("--") != -1) {
      x--;
    }
  }

  cout << x;
  return 0;
}