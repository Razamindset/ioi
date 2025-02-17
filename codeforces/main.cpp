#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r = 0;

  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end(), greater<int>());

  int i = 0;

  while (i < n) {
    if (arr[i] == 4) {
      r += 1;
      i++;
    } else if (i < n - 1 && (arr[i] + arr[i + 1] <= 4)) {
      r += 1;
      i += 2;
    } else {
      r += 1;
      i++;
    }
  }

  cout << r;

  return 0;
}
