#include <algorithm>
#include <vector>

int maxSequence(const std::vector<int>& arr) {
  //! Looks like we donot need to check for empty array and negative as the
  //! below algorithm handles that
  // Check if all the entries are negative
  //   if (std::all_of(arr.begin(), arr.end(), [](int num) { return num < 0; }))
  //   {
  //     return 0;
  //   }

  //* This is called the Kadane’s Algorithm
  int maxSum = 0;
  int current = 0;

  for (int num : arr) {
    current = std::max(0, current + num);
    maxSum = std::max(current, maxSum);
  }
  return maxSum;
}