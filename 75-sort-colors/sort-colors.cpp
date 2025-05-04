class Solution {
public:
    void sortColors(vector<int>& nums) { 
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        while(i <= r) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++, i++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--; 
                // dont increment i as we need to check that again whether that
                // is a 0 or 1 or 2
            } else {
                i++;
            }
        }
    }
};