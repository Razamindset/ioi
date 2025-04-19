#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int number;

  if (m > n) {
    number = m / 2;
    number += n;
  } else if (m == n) {
    number = m / 2;
    number += n;
  } else {
    number = n / 2;
    number += m;
  }

  cout << number;

  return 0;
}