class Solution {
public:
    int fnc(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==triangle.size()-1)return triangle[i][j];
        int down=  fnc(i+1,j,triangle,dp);
        int diagonal= fnc(i+1,j+1,triangle,dp);
        return dp[i][j]= min(down,diagonal)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
         vector<vector<int> > dp(n, vector<int>(n, -1));
        return fnc(0, 0,triangle,dp);
     
    }
};