class Solution {
public:
    int answer(int i, int j, vector<vector<int>>& grid, int dp[][200]) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return dp[i][j] = grid[i][j];
        }

        int down = (i + 1 < grid.size()) ? answer(i + 1, j, grid, dp) : INT_MAX;
        int right = (j + 1 < grid[0].size()) ? answer(i, j + 1, grid, dp) : INT_MAX;

        return dp[i][j] = min(down, right) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int dp[200][200];
        memset(dp, -1, sizeof(dp));
        return answer(0, 0, grid, dp);
    }
};