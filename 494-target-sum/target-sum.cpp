class Solution {
public:
    int fn(vector<int>& nums, int i, int currSum, int target, unordered_map<string, int>& dp) {
        // base case
        if(i >= nums.size()) {
            return currSum == target ? 1 : 0;
        }
        
        // create a unique key for memoization
        string key = to_string(i) + "," + to_string(currSum);
        
        // if already computed
        if(dp.find(key) != dp.end()) return dp[key];

        int ans = 0;
        // choice: add current number
        ans += fn(nums, i+1, currSum + nums[i], target, dp);

        // choice: subtract current number
        ans += fn(nums, i+1, currSum - nums[i], target, dp);

        return dp[key] = ans;   
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return fn(nums, 0, 0, target, dp);
    }
};