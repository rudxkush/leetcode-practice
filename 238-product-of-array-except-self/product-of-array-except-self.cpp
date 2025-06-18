class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n, 1);
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        int suffixProduct = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = prefixProduct[i] * suffixProduct;
            suffixProduct *= nums[i]; 
        }
        return ans;
    }
};

/*
    nums =         [1, 2, 3, 4]
    prefixProduct: [1, 1, 1, 1]
    ans:           [?, ?, ?, ?]
    prefixProduct: [1,  1,  2, 6]
    ans:           [24, 12, 8, 6]
*/