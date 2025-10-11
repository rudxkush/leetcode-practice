class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cache;
        cache[0] = 1;
        int subArrCount = 0;
        int runningSum = 0;

        for(int i = 0; i < n; i++) {
            runningSum += nums[i];
            int prevSum = runningSum - k;
            if(cache.count(prevSum)) {
                subArrCount += cache[prevSum];
            }
            cache[runningSum]++;
        }
        return subArrCount;
    }
};