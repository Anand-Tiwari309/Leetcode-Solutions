class Solution {
public:
    const int prime = 1e9 + 7;
    
    int fnc(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // Base cases
        if (j < 0) return 1; 
        if (i < 0) return 0; 
        if (dp[i][j] != -1) return dp[i][j];
        
        int result = 0;
        if (s[i] == t[j]) {
            int take_it = fnc(s, t, i - 1, j - 1, dp);
            int not_take = fnc(s, t, i - 1, j, dp);
            result = (take_it + not_take) % prime;
        } else {
            result = fnc(s, t, i - 1, j, dp);
        }
        dp[i][j] = result;
        return result;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fnc(s, t, n - 1, m - 1, dp); 
    }
};