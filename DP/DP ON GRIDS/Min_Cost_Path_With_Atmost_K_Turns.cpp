#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, m;
  int row[4] = {-1, 1, 0, 0};
  int col[4] = {0, 0, -1, 1};
  int dir[4] = {1, 2, 3, 4}; // U, D, L, R
  int dp[80][80][80][5];

  int f(int i, int j, int k, int prev, vector<vector<int>> &grid) {

    if (i == n - 1 && j == m - 1)
      return 0;

    int &ans = dp[i][j][k][prev];

    if (ans != -1)
      return ans;

    ans = 1e9;

    for (int d = 0; d < 4; d++) {
      int ni = i + row[d];
      int nj = j + col[d];

      if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
        int newK = k - (prev != 0 && prev != dir[d]);

        if (newK >= 0)
          ans = min(ans, grid[ni][nj] + f(ni, nj, newK, dir[d], grid));
      }
    }

    return ans;
  }

  int minCost(vector<vector<int>> &grid, int k) {
    n = grid.size();
    m = grid[0].size();

    memset(dp, -1, sizeof(dp));

    int ans = grid[0][0] + f(0, 0, k, 0, grid);

    return ans >= 1e9 ? -1 : ans;
  }
};