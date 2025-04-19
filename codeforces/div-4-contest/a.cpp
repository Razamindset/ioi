#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    string name;
    getline(cin, name);

    vector<string> parts;
    string current;

    for (auto &&ch : name) {
      if (ch != ' ') {
        current += ch;
      } else {
        parts.push_back(current);
        current = "";
      }
    }

    // if anything left in current
    if (!current.empty()) {
      parts.push_back(current);
    }

    // Build reduced form
    string reduced;
    for (string part : parts) {
      if (!part.empty()) reduced += part[0];
    }

    cout << reduced << endl;
  }

  return 0;
}
