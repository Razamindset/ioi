#include <iostream>

using namespace std;

int solution(int n) {
  if (n < 0) return 0;
  int sum = 0;

  for (int i = 3; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}

int main() {
  cout << solution(10) << endl;
  return 0;
}