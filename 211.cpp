class Solution {
public:
int rec(vector<int> &nums, int idx, vector<int> &dp)
{
    if(idx>=nums.size()) return 0;
    
    if(dp[idx]!=-1) return dp[idx];
    
    return dp[idx] = max(rec(nums, idx+1, dp), nums[idx]+rec(nums, idx+2, dp));
}

    int rob(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<nums.size();i++){
            if(i==0)arr1.push_back(nums[i]);
            else if(i==nums.size()-1)arr2.push_back(nums[i]);
            else{
                arr1.push_back(nums[i]);
                arr2.push_back(nums[i]);
            }
        }
        vector<int>dp1(arr1.size(),-1);
        vector<int>dp2(arr2.size(),-1);
        return max(rec(arr1,0,dp1),rec(arr2,0,dp2));
        
    }
};