int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
  if(ind==0)return 0;
  if(dp[ind]!=-1)return dp[ind];
  int mmSteps=INT_MAX;
  for(int j=1;j<=k;j++){
      if(ind-j>=0){
          int jump=solveUtil(ind-j, height, dp, k)+abs(height[ind]-height[ind-j]);
          mmSteps=min(mmSteps,jump);
      }
  }
  return dp[ind]=mmSteps;
}

int minimizeCost(int n, int k, vector<int>& height) {
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}
