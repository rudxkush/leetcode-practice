class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int l = 0;
       int r = 0;
       int maxLength = INT_MIN;
       int n = nums.size();
       int last = 0;
       while(r < n) { 
        while((last & nums[r]) != 0) {
            last ^= nums[l];
            l++;
        }
        last |= nums[r];
        maxLength = max(maxLength, r-l+1);
        r++;
       } 
       return maxLength;
    }
};