class Solution {
private:
    const int mod = 1e9 + 7;
    int n = 0;
    vector<long long> pprefix;
    vector<long long> prefix;
    vector<int> nse;
    vector<int> psee;

public:
    void build_prefix_arrays(vector<int>& strength) {
        prefix.assign(n + 1, 0);
        pprefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                (prefix[i] + strength[i]) % mod; // standard prefix sum
            pprefix[i + 1] =
                (pprefix[i] + prefix[i + 1]) % mod; // prefix of prefix
        }
    }
    void nearest_smaller_element_on_right(vector<int>& strength) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.top()] >= strength[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    void nearest_smaller_or_equal_element_on_left(vector<int>& strength) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.top()] > strength[i]) {
                st.pop();
            }
            if (!st.empty()) {
                psee[i] = st.top();
            }
            st.push(i);
        }
    }
    int totalStrength(vector<int>& strength) {
        n = strength.size();
        build_prefix_arrays(strength);

        nse.assign(n, n);
        nearest_smaller_element_on_right(strength);

        psee.assign(n, -1);
        nearest_smaller_or_equal_element_on_left(strength);

        auto modSub = [&](long long a, long long b) {
            return (a - b + mod) % mod;
        };

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left_count = i - psee[i];
            int right_count = nse[i] - i;

            long long total_left = modSub(pprefix[i], pprefix[max(0, psee[i])]);
            long long total_right = modSub(pprefix[nse[i]], pprefix[i]);

            long long contrib = (strength[i] % mod) *
                                (((left_count * total_right % mod -
                                   right_count * total_left % mod + mod) %
                                  mod)) %
                                mod;

            ans = (ans + contrib) % mod;
        }
        return ans;
    }
};