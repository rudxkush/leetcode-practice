class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid; // go left (including mid)
            } else {
                start = mid + 1; // go right
            }
        }
        return start;
    }
};
