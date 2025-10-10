class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int totalProduct = 1;
        unordered_set<int> st; // collect all the indices if any present!
        bool zeroPrs = false;  // zero -> present or not
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                totalProduct *= nums[i];
            } else {
                zeroPrs = true;
                st.insert(i);
            }
        }
        if (st.size() > 1) {
            return vector<int>(n, 0);
        } else if (zeroPrs) {
            result[*st.begin()] = totalProduct;
        } else {
            for (int i = 0; i < n; i++) {
                int productAtIndexI = totalProduct / nums[i];
                result[i] = productAtIndexI;
            }
        }
        return result;
    }
};