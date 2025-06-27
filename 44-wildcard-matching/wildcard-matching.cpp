class Solution {
public:
    vector<vector<int>> dp;
    bool matchDetector(string& s, string& p, int i, int j) {
        // base case
        if(i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (j < 0 && i >= 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = matchDetector(s, p, i - 1, j - 1);
        

        if(p[j] == '*') {
            return dp[i][j] = matchDetector(s, p, i - 1, j) || matchDetector(s, p, i, j - 1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return matchDetector(s, p, n - 1, m - 1);
    }
};