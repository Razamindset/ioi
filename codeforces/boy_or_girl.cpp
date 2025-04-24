#include <iostream>
#include <set>
using namespace std;

int main() {
  string username;
  cin >> username;

  set<char> seen;

  for (char ch : username) {
    seen.insert(ch);
  }

  if (seen.size() % 2 == 0) {
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }

  return 0;
}