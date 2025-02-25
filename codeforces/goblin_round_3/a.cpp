#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, k, p;

  cin >> t;

  while (t--) {
    cin >> n >> k >> p;
    vector<int> a(n, 0);

    // how can we ckeck if k is possible
    // We can do n*-p or n*+p if k is in range

    int maxSum = n * p;
    int minSum = n * (-p);

    if (k > maxSum || k < minSum) {
      cout << "-1\n";
      continue;
    }

    if (k == 0) {
      cout << "0\n";
      continue;
    }

    // If k is already achievable in one step
    if (k >= -p && k <= p) {
      cout << "1\n";
      continue;
    }

    // we can insert -p or +p at first and then add accordingly
    // if req is out of range add +p or -p as suitable
    int calculatedSum = 0;
    int tries = 1;

    a[0] = k >= 0 ? p : -p;
    calculatedSum += a[0];

    for (int i = 1; i < n; i++) {
      int required = k - calculatedSum;

      // If in range
      if (required >= -p && required <= p) {
        a[i] = required;
        calculatedSum += required;
        tries++;
        break;
      }

      if (required > 0) {
        calculatedSum += p;
      } else {
        calculatedSum += -p;
      }
      tries++;
    }

    if (calculatedSum == k) {
      cout << tries << "\n";
      continue;
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}