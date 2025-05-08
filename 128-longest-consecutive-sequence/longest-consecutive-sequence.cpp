class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> numSet(nums.begin(), nums.end());
        
        int maxLen = 1;
        int len = 1;
        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                int curr = num;
                while(numSet.find(curr + 1) != numSet.end()) {
                    len++;
                    curr++;
                }
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return maxLen;
    }
};