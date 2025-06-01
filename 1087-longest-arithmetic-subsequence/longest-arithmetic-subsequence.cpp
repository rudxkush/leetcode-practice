class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n); // nums & its difference
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int difference = nums[i] - nums[j];
                int len = dp[j].count(difference) ? dp[j][difference] + 1 : 2;
                dp[i][difference] = len;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};