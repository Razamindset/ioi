#include <iostream>
using namespace std;

int main() {
  long long m, n, a;
  cin >> m >> n >> a;

  long long tiles_in_n = n / a;
  long long tiles_in_m = m / a;

  if (n % a != 0) {
    tiles_in_n++;
  }
  if (m % a != 0) {
    tiles_in_m++;
  }

  // Tiles along n * along m = total tiles
  cout << tiles_in_m * tiles_in_n;

  return 0;
}