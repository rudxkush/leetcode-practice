class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int freq = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(freq > n/2) return ans;
            if(ans == nums[i]) {
                freq++;
            } else {
                freq--;
                if(freq == 0) {
                    ans = nums[i];
                    freq = 1;
                }
            }
        }
        return ans;
    }
};