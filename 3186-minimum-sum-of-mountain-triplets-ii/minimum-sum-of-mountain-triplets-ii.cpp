class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> minimum_on_right(n);
        minimum_on_right[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; --i) {
            minimum_on_right[i] = min(minimum_on_right[i + 1], nums[i]);
        }

        int previous_min_seen_so_far = nums[0];
        int ans = INT_MAX;
        for(int i = 1; i < n - 1; i++) {
            if(previous_min_seen_so_far < nums[i] && minimum_on_right[i] < nums[i]) {
                ans = min(ans, previous_min_seen_so_far + nums[i] +  minimum_on_right[i]);
            }
            previous_min_seen_so_far = min(previous_min_seen_so_far, nums[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    } 
};

/*
    triplets : nums[0] < nums[1] > nums[2]
    index : 0 < 1 < 2
*/