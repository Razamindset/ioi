#include <iostream>
using namespace std;

int main() {
  int n, k;

  cin >> n >> k;

  int next_part = 0;
  int scores[n];

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }

  int req_score = scores[k - 1];

  for (int score : scores) {
    if (score <= 0) continue;
    if (score >= req_score) {
      next_part++;
    }
  }

  cout << next_part;
  return 0;
}