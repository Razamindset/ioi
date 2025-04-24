#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;

  int value;

  for (int i = 0; i < s1.length(); i++) {
    if (tolower(s1[i]) == tolower(s2[i])) {
      value = 0;
    } else if (tolower(s1[i]) - 0 < tolower(s2[i]) - 0) {
      value = -1;
      break;

    } else {
      value = 1;
      break;
    }
  }

  // Use this way to convert character to number
  //   cout << 'a' - 0 << endl;
  //   cout << 'd' - 0 << endl;

  cout << value;
  return 0;
}