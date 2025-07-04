class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0;
        while(j < n) {
            sum += nums[j];
            while(sum > k) {
                sum -= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
        // unordered_map<int, int> sumMap;
        // sumMap[0] = 1; // Important: To handle subarrays starting from index 0
        // int count = 0, sum = 0;

        // for(int num : nums) {
        //     sum += num;
        //     count += sumMap[sum - goal]; // If sum-goal seen before, we have valid subarray
        //     sumMap[sum]++;
        // }
        // return count;


        // int n = nums.size();
        // vector<int> prefix(n, 0);
        // prefix[0] = nums[0];
        // for(int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i - 1] + nums[i];
        // }
        // int count = 0;
        // unordered_map<int, int> sumMap;
        // for(int i = 0; i < n; i++) {
        //     int temp = prefix[i] - goal;
        //     if(sumMap.find(temp) != sumMap.end()) {
        //         count += sumMap[temp];
        //     }
        //     if(prefix[i] == goal) count++; // Special case: subarray from index 0
        //     sumMap[prefix[i]]++;
        // }
        // return count;
    }
};
