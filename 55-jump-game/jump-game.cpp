class Solution {
public:
    vector<int> dp;
    bool cJHelper(vector<int>& nums, int i) {
        if(i >= nums.size() - 1) return true;
        if(dp[i] != -1) return dp[i];

        bool can = false;
        for(int j = 1; j <= nums[i]; j++) {
            if(cJHelper(nums, i + j))
               return true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return cJHelper(nums, 0);
    }
};