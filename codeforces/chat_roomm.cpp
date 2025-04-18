#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;

  // !This is alos called the two pointer technique we use one pointer for s and
  // one for target

  string target_hell = "hello";

  int target_position = 0;

  // Move through s
  for (int i = 0; i < s.length(); i++) {
    // If target character is found then move one pos ahead
    if (s[i] == target_hell[target_position]) {
      target_position++;
    }
  }

  cout << (target_position == target_hell.length() ? "YES" : "NO");

  return 0;
}