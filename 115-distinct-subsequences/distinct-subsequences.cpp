class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // match + skip
                } else {
                    dp[i][j] = dp[i - 1][j]; // skip s[i-1]
                }
            }
        }

        return (int)dp[n][m];
    }
};


/*
      r a b b b i t   
    1 1 1 1 1 1 1 1   
r   0 1 1 1 1 1 1 1
a   0 1 2 2 2 2 2 2
b   0 1 2 4 6 6 6 6
b   0 1 2 4 10 16 16 16
i   0 1 2 4 10 16 16 16
t   0 1 2 4 10 16 16 20
*/