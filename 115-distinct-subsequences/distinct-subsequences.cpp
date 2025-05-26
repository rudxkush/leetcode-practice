class Solution {
public:
    vector<vector<int>> dp;
    int n = 0, m = 0;
    int solve(int i, int j, string& s, string& t) {
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int res = 0;
        if(s[i] == t[j]) 
            res += solve(i + 1, j + 1, s, t);

        res += solve(i + 1, j, s, t);

        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, s, t);
    }
};