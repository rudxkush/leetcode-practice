class Solution {
public:
    vector<vector<int>> dp;
    bool knapsack(vector<int>& nums, int i, int target) {
        // base case
        if(i < 0) {
            if(target == 0) {
                return true;
            }
            return false;
        }

        // if already computed!
        if(dp[i][target] != -1) return dp[i][target];

        bool left = 0;
        if(nums[i] <= target) {
            left = knapsack(nums, i - 1, target - nums[i]);
        }

        bool right = knapsack(nums, i - 1, target);

        return dp[i][target] = left || right;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        dp.assign(n, vector<int> (target + 1, -1));
        return knapsack(nums, n - 1, target);
    }
};