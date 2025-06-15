class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; 
        int prefixSum = 0;
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int val = (nums[i] == 0) ? -1 : 1;
            prefixSum += val;
            if(prefixMap.count(prefixSum)) {
                maxLen = max(maxLen, i - prefixMap[prefixSum]);
            } else {
                prefixMap[prefixSum] = i;
            }
        }
        return maxLen;
    }
};

/*

    Try to consider 0s as -1s and 1s as +1s
    nums   = [ 0  1 1 1 1 1 0 0 0 ]
    Prefix = [ -1 0 1 2 3 4 3 2 1 ]

*/