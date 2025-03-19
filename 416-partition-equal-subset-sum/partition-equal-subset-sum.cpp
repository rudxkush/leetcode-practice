class Solution {
public:
    bool equalSum(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        // base case
        if(target == 0) {
            return true;
        }
        if(i >= nums.size() || target < 0) return false;
        // if already computed!
        if(dp[i][target] != -1) return dp[i][target];

        bool result = equalSum(nums, i+1, target - nums[i], dp) || equalSum(nums, i+1, target, dp);
        return dp[i][target] = result;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
           totalSum += nums[i];
        }
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2; 

        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return equalSum(nums, 0, target, dp);
    }
};