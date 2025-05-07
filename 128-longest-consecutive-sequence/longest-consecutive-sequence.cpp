class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
         if (nums.empty()) return 0;
        int maxLen = 0;

        for(int num : numSet) {
            // only process the numbers that 
            // are start of something
            if(numSet.find(num - 1) == numSet.end()) {
                int curr = num;
                int len = 1;
                while(numSet.find(curr + 1) != numSet.end()) {
                    len++;
                    curr++; 
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};