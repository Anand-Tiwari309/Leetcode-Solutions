class Solution {
public:
    int answer(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return dp[i][j] = grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = (i > 0) ? answer(i - 1, j, grid, dp) : INT_MAX;
        int left = (j > 0) ? answer(i, j - 1, grid, dp) : INT_MAX;

        return dp[i][j] = min(up, left) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return answer(n - 1, m - 1, grid, dp);
    }
};