class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // I would just store gR **prefix**
        vector<int> gR(n);
        gR[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            gR[i] = max(gR[i + 1], height[i]);
        }
        int sum = 0;
        int gL = height[0];
        for (int i = 0; i < n; i++) {
            int minHeight = min(gL, gR[i]);
            if (minHeight > height[i])
                sum += minHeight - height[i];
            // update gL
            gL = max(gL, height[i]);
        }
        return sum;
    }
};