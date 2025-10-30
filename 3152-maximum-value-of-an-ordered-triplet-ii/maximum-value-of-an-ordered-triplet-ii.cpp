class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;          
        long long maxPrefix = 0;       // max nums[i] seen so far
        long long maxDifference = 0;   // max (nums[i] - nums[j]) seen so far

        for (int k = 0; k < n; ++k) {
            result = max(result, maxDifference * nums[k]);
            maxDifference = max(maxDifference, maxPrefix - nums[k]);
            maxPrefix = max(maxPrefix, (long long) nums[k]);
        }
        return result;
    }
};
