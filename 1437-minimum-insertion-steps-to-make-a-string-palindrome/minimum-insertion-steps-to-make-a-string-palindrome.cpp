class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string h = s;
        reverse(h.begin(), h.end());

        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == h[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }
        
        return (n - lcs[n][n]);
    }
};