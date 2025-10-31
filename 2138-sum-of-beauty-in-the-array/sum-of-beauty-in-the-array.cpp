class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int leftMax = nums[0];
        int sum = 0;
        for(int i = 1; i < n - 1; i++) {
            if(leftMax < nums[i] && nums[i] < rightMin[i + 1]) {
                sum += 2;
            } else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum += 1;
            }
            leftMax = max(leftMax, nums[i]);
        }
        return sum;
    }
};

/*
    1 - (n-2)
    beauty(nums[i]) =

    2, nums[j] < nums[i] < nums[k], 0 <= j, j < i < k, k <= n -1
    1, nums[i - 1] < nums[i] < nums[i + 1] 

*/