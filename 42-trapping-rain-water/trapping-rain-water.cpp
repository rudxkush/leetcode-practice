class Solution {
public:
    int trap(vector<int>& height) {
        int n =  height.size();
        vector<int> prefix(n), suffix(n);
        int max1 = height[0];
        for(int i = 0; i < n; i++) {
            max1 = max(max1, height[i]);
            prefix[i] = max1;
        }
        int max2 = height[n-1];
        for(int i = n-1; i >= 0; i--) {
            max2 = max(max2, height[i]);
            suffix[i] = max2;
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            int leftMax = prefix[i], rightMax = suffix[i];
            if(height[i] < leftMax && height[i] < rightMax) {
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};