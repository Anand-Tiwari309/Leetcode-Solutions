//way1
class Solution {
public:
int solve(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    
    return prev;  // Return the maximum sum
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        return solve(n,nums );
    }
};

//way2
class Solution {
public:
int rec(vector<int> &nums, int idx, vector<int> &dp)
{
    if(idx>=nums.size()) return 0;
    
    if(dp[idx]!=-1) return dp[idx];
    
    return dp[idx] = max(rec(nums, idx+1, dp), nums[idx]+rec(nums, idx+2, dp));
}

int rob(vector<int>& nums) 
{
    vector<int> dp(nums.size()+1, -1);
    return rec(nums, 0, dp);
    
}
};
//way 3
int solveUtil(int n, vector<int>& arr, vector<int>& dp) {
    // Base case: If there are no elements in the array, return 0
    dp[0] = arr[0];
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        dp[i] = max(pick, nonPick);
    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];
}
