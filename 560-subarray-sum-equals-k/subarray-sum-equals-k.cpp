class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int n = nums.size();
        int prefixSum = 0, count = 0;
        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int excludedSum = prefixSum - k;
            if(mp.find(excludedSum) != mp.end()) {
                count += mp[excludedSum];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};


/*
    Try to generate the sum of all the subarrays
    and then return the count of all subarray's sum matching to k 
*/
/*
    Will Prefix sum help? Yes!

    nums = [1,1,1], k = 2
    Output: 2
    Ex1 : ps : 1 2 3
    map :{
    {0,  1}
    {1,  1} -> {1, 2} updated at i = 2
    {2,  1}
    }
    prefixSum = 1, excludedSum = 1 - 2 = -1
    prefixSum = 2, excludedSum = 2 - 2 =  0 -> count += mp[excludedSum];
    prefixSum = 3, excludedSum = 3 - 2 =  1 -> count += mp[excludedSum];

    count = 2

    nums = [1,2,3], k = 3
    Output: 2
    Ex2 : ps : 1 3 6
     
    https://leetcode.com/problems/contiguous-array/description/
    https://leetcode.com/problems/subarray-sum-equals-k/description/
    https://leetcode.com/problems/subarrays-with-k-different-integers/description/
    https://leetcode.com/problems/count-number-of-nice-subarrays/description/
    https://leetcode.com/problems/binary-subarrays-with-sum/description/
    https://leetcode.com/problems/subarray-product-less-than-k/description/
    https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
*/