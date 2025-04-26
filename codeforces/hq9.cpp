#include <iostream>
using namespace std;

int main() {
  string instructions;

  cin >> instructions;

  bool will_print = false;

  for (char ins : instructions) {
    if (ins == 'H' || ins == 'Q' || ins == '9') {
      will_print = true;
      break;
    }
  }

  if (will_print) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}