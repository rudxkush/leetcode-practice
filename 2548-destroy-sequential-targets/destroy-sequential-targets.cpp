class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        for(int i = 0; i < n; i++) {
            int target = nums[i] % space;
            freqMap[target]++; 
        }
        int maxFreq = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int rem = nums[i] % space;
            int freq = freqMap[rem];

            if(freq > maxFreq) {
                maxFreq = freq;
                ans = nums[i];
            } else if (freq == maxFreq) {
                ans = min(ans, nums[i]);
            }
        }
        return ans;
    }
};

/*
[3  7  8  1  1  5]
space = 2
if should be multiple of space 
nums[i] % space shoule be there in the array and 
also the one that has the longest lenght would be our answer
*/