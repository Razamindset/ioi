#include <iostream>
using namespace std;

bool isLucky(int number) {
  // Check all the digits
  string str_numb = to_string(number);
  bool is_perfect = true;

  for (char ch : str_numb) {
    if (ch != '4' && ch != '7') {
      is_perfect = false;
      break;
    }
  }

  return is_perfect;
}

int main() {
  int number;
  cin >> number;

  bool is_lucky = false;

  // Directly check if lucky
  is_lucky = isLucky(number);

  if (is_lucky) {
    cout << "YES";
    return 0;
  }

  // Loop all the numbers and check if divisible by a lucky number
  for (int i = 4; i < number; i++) {
    if (isLucky(i)) {
      //   Lucky if contains the digits 4 and 7 only or is divided by 4 or 7
      if (number % i == 0) {
        is_lucky = true;
        break;
      }
    }
  }

  if (is_lucky) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}