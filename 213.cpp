class Solution {
public:
   
    int path(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0){
            return 1;
        }
        if(x <0 || y <0){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        else
        return dp[x][y] = path(x-1, y, dp) + path(x, y-1,dp);
        
    }

    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m, vector<int>(n, -1));
    return path(m-1, n-1, dp);
        
    }
};
