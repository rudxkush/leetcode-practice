class Solution {
public:
    vector<vector<int>> dp;

    int helper(string& s, int i, int j) {
        // Base cases
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = 2 + helper(s, i + 1, j - 1);
        } else {
            dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(s, 0, n - 1);
    }
};
