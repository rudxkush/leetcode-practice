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
};
/*
class bruteSolution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b = 1;
            j = i - 1;
            while (j >= 0 && heights[j] >= l) {
                b++;
                j--;
            }
            j = i + 1;
            while (j < n && heights[j] >= l) {
                b++;
                j++;
            }
            int area = l * b;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
*/