class Solution {
public:
    int totals(vector<int>& nums, int i, int xorValue) {
        // Base case
        if (i == nums.size()) {
            return xorValue;
        }
        // Include 
        int include = totals(nums, i + 1, xorValue ^ nums[i]);
        // Exclude 
        int exclude = totals(nums, i + 1, xorValue);

        return include + exclude;
    }
    
    int subsetXORSum(vector<int>& nums) {
        return totals(nums, 0, 0);
    }
};