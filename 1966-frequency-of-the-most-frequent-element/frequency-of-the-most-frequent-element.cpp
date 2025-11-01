class Solution {
public:
    int getMaxCountAtIndex(int idx, int k, vector<int>& nums, vector<long long>& prefixSum) {
        int target = nums[idx];
        int left = 0, right = idx;
        int bestLeft = idx;

        while (left <= right) {
            int mid = (left + right) / 2;
            long long totalElements = idx - mid + 1;
            long long requiredSum = totalElements * target;
            long long currentSum = prefixSum[idx] - prefixSum[mid] + nums[mid];
            long long opsNeeded = requiredSum - currentSum;

            if (opsNeeded > k) {
                left = mid + 1;
            } else {
                bestLeft = mid;
                right = mid - 1;
            }
        }

        return idx - bestLeft + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int maxFreq = 0;
        for (int i = 0; i < n; ++i) {
            maxFreq = max(maxFreq, getMaxCountAtIndex(i, k, nums, prefixSum));
        }

        return maxFreq;
    }
};
