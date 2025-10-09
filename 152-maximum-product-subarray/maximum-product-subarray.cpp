class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxProduct = INT_MIN;
        for(int start = 0; start < n; start++) {
            int product = 1;
            for(int end = start; end < n; end++) {
                product *= arr[end];
                maxProduct = max(maxProduct, product);
            }
        }
        return maxProduct;
    }
};