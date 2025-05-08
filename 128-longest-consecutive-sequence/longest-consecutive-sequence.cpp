class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;

        int maxLen = 1;
        int len = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] + 1 == nums[i + 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else if(nums[i] + 1 != nums[i + 1] && nums[i] != nums[i + 1]){ // also to skip duplicates
                len = 1;
            }
        }
        return maxLen;
    }
};