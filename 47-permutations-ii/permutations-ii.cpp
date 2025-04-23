class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int i) {
        // base case
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        // choices
        unordered_set<int> seen;
        for(int j = i; j < nums.size(); j++) {
            if (seen.count(nums[j])) continue;
            seen.insert(nums[j]);
            swap(nums[i], nums[j]); // choose
            backtrack(nums, i + 1); // move forward
            swap(nums[i], nums[j]); // backtrack
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};