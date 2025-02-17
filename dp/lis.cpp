#include <algorithm>
#include <iostream>
#include <vector>

int LIS_DP(std::vector<int> arr) {
  // To solve this problem we need to find the strictly longest incraesing
  // subsequnce in an array We can solve this by using a dp with O(n2)
  // performance
  int n = arr.size();

  // Dp will keep track of the lenght of the subsequence
  // We guive it a len n and set all elements to 1
  std::vector<int> dp(n, 1);

  int maxLen = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        // We just add one to the previous value stored in dp
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    maxLen = std::max(maxLen, dp[i]);
  }

  return maxLen;
}

int LIS_Binary(std::vector<int> arr) {
  std::vector<int> tail;

  for (int num : arr) {
    // lower bound returns an iterator/location where we can put the num without
    // breaking the order. If there is no such place it returns .end() so we can
    // append it to the last

    auto it = std::lower_bound(tail.begin(), tail.end(), num);

    // Append to the last if no such pos found
    if (it == tail.end()) {
      tail.push_back(num);

    } else {
      // if such postion is found replace that with num
      *it = num;
    }
  }

  //* Following chatgpt example proves helpful when understanding this problem
  // Step	Element	tail[] Array	Action
  // 1	10	{10}	New LIS starts
  // 2	22	{10, 22}	Append (22 > 10)
  // 3	9	{9, 22}	Replace 10 with 9 (lower_bound(10) → index 0)
  // 4	33	{9, 22, 33}	Append (33 > 22)
  // 5	21	{9, 21, 33}	Replace 22 with 21 (lower_bound(22) → index 1)
  // 6	50	{9, 21, 33, 50}	Append (50 > 33)
  // 7	41	{9, 21, 33, 41}	Replace 50 with 41 (lower_bound(50) → index 3)
  // 8	60	{9, 21, 33, 41, 60}	Append (60 > 41)

  // The tails array will contain the smallest possible ends of the increasing
  // subsequence
  return tail.size();
}

int main() {
  std::vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
  // std::cout << "Length of LIS: " << LIS_DP(arr) << std::endl;

  std::cout << "Length of LIS: " << LIS_Binary(arr) << std::endl;

  return 0;
}