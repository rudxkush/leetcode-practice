class Solution { // bottom up 
public:
    vector<vector<int>> dp;
    int knapsack(vector<int>& nums, int i, int prev) {
        // base case
        if(i >= nums.size()) {
            return 0;
        }

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        // inclusion
        int include = 0; 
        if(prev == -1 || nums[i] > nums[prev])
            include = 1 + knapsack(nums, i + 1, i);

        // exclusion
        int exclude = knapsack(nums, i + 1, prev);

        return dp[i][prev + 1] = max(include, exclude);  
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int> (n + 1, -1));
        return knapsack(nums, 0, -1);
    }
};