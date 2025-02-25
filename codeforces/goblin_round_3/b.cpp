#include <iostream>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string money;
    cin >> money;

    //! first i thought i would have to use dp
    // We need 2 dashes and one underscore to construct a unit money
    long long dashesCount = 0, underscoreCount = 0;

    // The string only consists of dashes and underscors so let  me count them
    for (char ch : money) {
      if (ch == '-') {
        dashesCount++;
      } else {
        underscoreCount++;
      }
    }

    long long firstDahses = dashesCount / 2;
    long long lastDahses = dashesCount - firstDahses;

    //! Glad i studied math for high school formula is as:
    // Total combination = Choices for first spot * choices for second spot *
    // choices for last spot
    cout << firstDahses * underscoreCount * lastDahses << "\n";
  }

  return 0;
}