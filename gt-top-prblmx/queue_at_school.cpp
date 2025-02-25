#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  std::string queue;

  cin >> queue;

  /// Loop over the array and check ith and ith +1 index
  // If a boy at i and a girl at i+1 then swap

  while (t--) {
    for (int i = 0; i < n; i++) {
      if (i + 1 < n) {
        if (queue[i] == 'B' && queue[i + 1] == 'G') {
          queue[i] = 'G';
          queue[i + 1] = 'B';
          i++;  // If swapped no need to check the next index
        }
      }
    }
  }

  cout << queue;

  return 0;
}