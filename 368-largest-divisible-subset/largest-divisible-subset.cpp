class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> previousIndex(n, -1);
        int maxLength = 1, lastIndex = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    previousIndex[i] = j;
                }
            }
            if(dp[i] > maxLength) {
                maxLength = max(dp[i], maxLength);
                lastIndex = i;
            }
        }
        // build the LIS sequence here ->
        vector<int> ans;
        for(int i = lastIndex; i >= 0; ) {
            ans.push_back(nums[i]);
            if(previousIndex[i] == -1) break;
            i = previousIndex[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/*
    subset - [1. 2]
             [1, 3]
--------------------------------------------------------------------------------------
    arr[i] = [1, 2, 4, 8]
    answer[i] % answer[j] == 0 || answer[j] % answer[i] == 0
    1 % 2 || 2 % 1 -> true
    2 % 4 || 4 % 2 -> true
    4 % 8 || 8 % 4 -> true
    if we could sort it and then we can also manage to get the LIS them 
    we would be able to solve this particular problem as then all
    the pairs of the answer is gonna follow the conditions.
 */