class Solution {
public:
    int dp[501][501];
    int lcs(int i, int j, string& s1, string& s2) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = lcs(i - 1, j, s1, s2);
        ans = max(ans, lcs(i, j - 1, s1, s2));
        ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
    }
    int minDistance(string word1, string word2) {
      int t=longestCommonSubsequence(word1,word2);
     return (word1.length()-t)+(word2.length()-t);
    }
};