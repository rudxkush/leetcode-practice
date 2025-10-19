class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> st; 
        st.reserve(n + 1);
        long long best = 0;

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];          // trailing zero flush
            while (!st.empty() && heights[st.back()] > h) {
                int mid = st.back(); st.pop_back();
                int left = st.empty() ? 0 : st.back() + 1;
                int right = i - 1;
                long long area = 1LL * heights[mid] * (right - left + 1);
                best = max(best, area);
            }
            st.push_back(i);
        }
        return (int)best;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> heights(col, 0);
        int ans = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int temp = largestRectangleArea(heights);
            ans = max(temp, ans);
        }
        return ans;
    }
};