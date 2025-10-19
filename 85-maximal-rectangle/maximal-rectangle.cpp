class Solution {
public:
    vector<int> nearestSmallerElementOnRight(vector<int>& heights, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = n;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nearestSmallerElementOnLeft(vector<int>& heights, int n) {
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = -1;
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsei = nearestSmallerElementOnRight(heights, n);
        vector<int> psei = nearestSmallerElementOnLeft(heights, n);
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b = nsei[i] - psei[i] - 1;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
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