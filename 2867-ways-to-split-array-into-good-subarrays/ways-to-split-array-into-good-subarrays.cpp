class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> onesPosition;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                onesPosition.push_back(i);
            }
        }
        int m = onesPosition.size();
        if (m <= 1) return m;
        long long result = 1;
        for (int i = 0; i < m - 1; i++) {
            int left = onesPosition[i];
            int right = onesPosition[i + 1];
            int zeroesBetween = (right - left - 1)%MOD;
            result = (result * (zeroesBetween + 1)) % MOD;
        }
        return (int)result;
    }
};