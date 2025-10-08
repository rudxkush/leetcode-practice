class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int freq = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(candidate == nums[i]) {
                freq++;
                candidate = nums[i];
            } else {
                freq--;
                if(freq == 0) {
                    candidate = nums[i];
                    freq = 1;
                }
            }
        }
        return candidate;
    }
};
// 3, 2, 3
// candidate = 3
// freq = 1

// i = 0, freq = 1, candidate = 3
// i = 1, freq = 0, candidate = 2
// i = 2 , freq = 