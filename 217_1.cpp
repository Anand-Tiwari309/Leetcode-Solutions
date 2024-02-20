class Solution {
public:
    int fnc(int i, int j, int n, const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (i == n - 1) {
            return matrix[i][j];
        }
        int left_diagonal = (j > 0) ? fnc(i + 1, j - 1, n, matrix, dp) : INT_MAX;
        int right_diagonal = (j < n - 1) ? fnc(i + 1, j + 1, n, matrix, dp) : INT_MAX;
        int down = fnc(i + 1, j, n, matrix, dp);

        return dp[i][j] = matrix[i][j] + std::min(down, std::min(left_diagonal, right_diagonal));
    }

    int minFallingPathSum(const std::vector<std::vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            ans = std::min(ans, fnc(0, i, n, matrix, dp));
        }

        return ans;
    }
};