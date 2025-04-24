#include <iostream>
#include <string>
using namespace std;

int main() {
  string vowels = "aoyeui";
  string word, nw_word;

  cin >> word;

  for (char ch : word) {
    char lowered = tolower(ch);

    if (vowels.find(lowered) == string::npos) {
      nw_word += '.';
      nw_word += lowered;
    }
  }

  cout << nw_word << endl;

  return 0;
}