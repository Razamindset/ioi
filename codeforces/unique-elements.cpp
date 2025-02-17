#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int m, n;
  cin >> n >> m;

  vector<int> arr(n), distinct_cout(n);
  unordered_set<int> seen;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int j = n - 1; j >= 0; j--) {
    seen.insert(arr[j]);
    distinct_cout[j] = seen.size();
  }

  while (m--) {
    int li;
    cin >> li;
    cout << distinct_cout[li - 1] << "\n";
  }

  return 0;
}
