#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
  // dp is also a mxn vector where dp[i][j] willl be the number of ways we can
  // reach (i, j) form (0, 0)
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      // Appply the transition formula to get the number of ways
      // the number of ways is equal to the ways required to reach the previous
      // top element + ways to reach the left element
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}

int spaceOptimizdedUniquePaths(int m, int n) {
  // So the key idea is instead of using 2d array use a 1d array in which dp[j]
  // is for the ways from top and dp[j-1] is for the wasy from left
  std::vector<int> dp(n, 1);

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      // here the last value wll be used adn then updated
      dp[j] += dp[j - 1];
    }
  }

  return dp[n - 1];
}

int uniquePathsBlocked(std::vector<std::vector<int>>& arr, int m, int n) {
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

  if (arr[0][0] == 1) return 0;
  dp[0][0] = 1;

  // So we need to fill the first row and first column first

  // for(){}

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      // The diffrence is if we find 1 at i, j then we set dp[i][j] = 0 means
      // cannot user that path
      if (arr[i][j] == 1) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}

int main() {
  int m = 3, n = 4;
  // std::cout << "Unique Paths: " << uniquePaths(m, n) << std::endl;
  // std::cout << "Unique Paths: " << spaceOptimizdedUniquePaths(m, n)
  //           << std::endl;

  int grid[m][n] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  // std::cout << "Unique Paths: " << uniquePathsBlocked(grid, m, n) <<
  // std::endl;

  return 0;
}