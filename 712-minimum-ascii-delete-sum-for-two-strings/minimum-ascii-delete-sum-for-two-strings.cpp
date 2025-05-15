class Solution {
public:
    int lcs(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    lcs[i][j] = s1[i - 1] + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        return lcs[n][m];
    }
    int minimumDeleteSum(string s1, string s2) {
        int lcsAscii = lcs(s1, s2);

        int totolAscii = 0;
        for (auto ch : s1) totolAscii += ch;
        for (auto ch : s2) totolAscii += ch;

        return totolAscii - 2 * lcsAscii;
    }
};