#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n][3];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }

  // We need to sum each col
  int c1 = 0, c2 = 0, c3 = 0;

  for (int i = 0; i < n; i++) {
    c1 += arr[i][0];
  }

  for (int i = 0; i < n; i++) {
    c2 += arr[i][1];
  }

  for (int i = 0; i < n; i++) {
    c3 += arr[i][2];
  }

  if (c1 == 0 && c2 == 0 && c3 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}