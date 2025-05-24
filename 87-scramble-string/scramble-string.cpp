class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool solve(string& s1, string& s2, int i1, int i2, int len) {
        // Base case
        if (s1.substr(i1, len) == s2.substr(i2, len)) return true;
        if (len == 1) return false;
        if (dp[i1][i2][len] != -1) return dp[i1][i2][len];

        for (int k = 1; k < len; ++k) {
            // No swap
            if (solve(s1, s2, i1, i2, k) &&
                solve(s1, s2, i1 + k, i2 + k, len - k))
                return dp[i1][i2][len] = true;

            // Swap
            if (solve(s1, s2, i1, i2 + len - k, k) &&
                solve(s1, s2, i1 + k, i2, len - k))
                return dp[i1][i2][len] = true;
        }

        return dp[i1][i2][len] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        dp.assign(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(s1, s2, 0, 0, n);
    }
};
