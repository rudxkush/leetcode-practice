class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
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

    vector<int> prevSmallerOrEqualElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
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

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = prevSmallerOrEqualElement(arr);

        int total = 0, n = arr.size();
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};
// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int total = 0, n = arr.size();
//         int mod = (int)(1e9 + 7);
//         for (int i = 0; i < n; i++) {
//             int mini = arr[i];
//             for(int j = i; j < n; j++) {
//                 mini = min(arr[j], mini);
//                 total = (total + mini) % mod;
//             }
//         }
//         return total;
//     }
// };