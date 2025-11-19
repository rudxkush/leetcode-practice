class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int maxLength = INT_MIN;
        int zeroes = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                zeroes++;
            while (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            if (zeroes <= k) {
                if ((right - left + 1) > maxLength) {
                    maxLength = right - left + 1;
                }
            }
        }
        return maxLength;
    }
};