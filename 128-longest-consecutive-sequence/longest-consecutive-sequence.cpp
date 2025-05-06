class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sorting
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int maxLength = 1;
        int len = 1;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] + 1 == nums[i + 1]) {
                len++; 
                maxLength = max(len, maxLength);
            } else if(nums[i] + 1 != nums[i + 1] && nums[i] != nums[i + 1]){
                len = 1;
            }
        }
        return maxLength;
    }
};