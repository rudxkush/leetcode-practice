class Solution {
public:
    typedef long long ll;
    int maxFrequencyScore(vector<int>& nums, long long k) {
        ll n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        ll maxWindow = 0;
        ll l = 0, r = 0;
        while(r < n) {
            r++; // Window is now [l, r)

            ll mid = l + (r - l)/2;
            ll target = nums[mid];
            ll leftLen = mid - l;
            ll rightLen = r - mid;

            // Note: We use prefixSum[mid] and prefixSum[l] for the left part
            ll leftCost = target * leftLen - (prefixSum[mid] - prefixSum[l]);
            // Note: We use prefixSum[r] and prefixSum[mid] for the right part
            ll rightCost = (prefixSum[r] - prefixSum[mid]) - target * rightLen;

            // Shrink the window
            while(leftCost + rightCost > k) {
                l++; // Shrink from the left

                // Recalculate cost for the new window [l, r)
                mid = l + (r - l)/2;
                target = nums[mid];
                leftLen = mid - l;
                rightLen = r - mid;
                leftCost = target * leftLen - (prefixSum[mid] - prefixSum[l]);
                rightCost = (prefixSum[r] - prefixSum[mid]) - target * rightLen;
            }

            maxWindow = max(maxWindow, r - l);
        }
        return (int) maxWindow;
    }
};