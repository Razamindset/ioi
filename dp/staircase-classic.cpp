#include <iostream>
#include <vector>

int memoizeStaricase(int n, std::vector<int>& dp) {
  // We can store the alrady computed results in a vector and return if found
  // else we compute and add them to the vector for future use

  // We can deduce until we can get 0 means no steps left
  if (n == 0 || n == 1) {
    return 1;
  }

  if (dp[n] != -1) {
    // If a value is found
    return dp[n];
  }

  return dp[n] = memoizeStaricase(n - 2, dp) + memoizeStaricase(n - 1, dp);
}

int solveStaircaseRecursive(int n) {
  // So we are given an n lenght of staricase and each time we can only climb 1
  // or 2 steps. We need to find the total distinct combinations possible

  // if n=4 -> 4-1 or 4-2
  // 3 -> 2 or 1
  // 2 -> 2-1 or 2-2

  // We initialize a vector with sizwe n+1 and all values to -1
  std::vector<int> dp(n + 1, -1);
  return memoizeStaricase(n, dp);
}

int solveStairCaseTabularWithArray(int n) {
  // This one is O(n) but we can further optimize it by by using only two
  // variables as we needthe last two elements fo the array only
  if (n == 0 || n == 1) return 1;

  int dp[n + 1];
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int stairCaseOptimized(int n) {
  if (n == 1 || n == 0) return 1;

  int lower = 1;
  int upper = 1;

  for (int i = 2; i <= n; i++) {
    int sum = lower + upper;
    lower = upper;
    upper = sum;
  }

  return upper;
}

int main() {
  //   std::cout << solveStaircaseRecursive(40);
  std::cout << stairCaseOptimized(40);

  std::cout << "\n";
  return 0;
}