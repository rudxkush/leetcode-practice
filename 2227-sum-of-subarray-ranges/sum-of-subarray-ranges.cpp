class Solution {
public: 
    // Time complexity O(5n) 
    // Space complexity O(8n)
    vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = n;
            } else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevSmallerOrEqualElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = n;
            } else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> prevGreaterOrEqualElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse = nextSmallerElement(nums);
        vector<int> psee = prevSmallerOrEqualElement(nums);

        vector<int> nge = nextGreaterElement(nums);
        vector<int> pgee = prevGreaterOrEqualElement(nums);

        int n = nums.size();
        long long totalMax = 0;
        long long totalMin = 0;
        for (int i = 0; i < n; i++) {
            int nse_ahead = nse[i] - i;
            int psee_behind = i - psee[i];

            totalMin += (long long)nse_ahead * psee_behind * nums[i];

            int nge_ahead = nge[i] - i;
            int pgee_behind = i - pgee[i];

            totalMax += (long long)nge_ahead * pgee_behind * nums[i];
        }
        return totalMax - totalMin;
    }
};