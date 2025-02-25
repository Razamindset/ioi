#include <iostream>
using namespace std;

int main() {
  int matrix[5][5];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
    }
  }

  // So we need to move the 1 to the 3rd row and 3rd column
  int col;
  int row;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (matrix[i][j] == 1) {
        row = i;
        col = j;
      }
    }
  }

  col++;
  row++;
  int res = 0;

  res += abs(3 - col);
  res += abs(3 - row);

  cout << res << endl;
  return 0;
}