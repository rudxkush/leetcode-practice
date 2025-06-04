class Solution {
public:
    vector<int> dp;
    int n = 0;
    int solve(vector<int>& nums, int target) {
        // base case
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int ways = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= target) {
                ways += solve(nums, target - nums[i]);
            }
        }
        return dp[target] = ways; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();  
        dp.assign(target + 1, -1);
        return solve(nums, target);
    }
};


/*
    
    1   2   3
    target = 4

    1  1  1  1 -> first way that sums to target
    1  1  2    -> second way that sums to target
    1  2  1    -> third way that sums to target
    1  3       -> fourth way that sums to target
    .....so on

    output - 7


*/