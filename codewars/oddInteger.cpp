#include <iostream>
#include <unordered_map>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  std::unordered_map<int, int> seen;
  int oddTimes;

  for (int num : numbers) {
    seen[num]++;
  }

  for (const auto& pair : seen) {
    if (pair.second % 2 != 0) {
      return pair.first;
    }
  }

  return -1;  // Number not found Ideally it wil never be executed
}

int main() {
  std::vector<int> test = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};

  std::cout << findOdd(test);
}