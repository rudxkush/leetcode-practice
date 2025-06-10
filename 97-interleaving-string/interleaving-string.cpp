class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    bool solve(string& s1, string& s2, string& s3, int i, int j) {
        // base case 
        if(i == n && j == m) 
            return true;
        
        if(dp[i][j] != -1) return dp[i][j];

        bool ans = 0;
        // pick s1
        if(i < n && s3[i + j] == s1[i])
            ans |= solve(s1, s2, s3, i + 1, j);

        // pick s2
        if(j < m && s3[i + j] == s2[j])
            ans |= solve(s1, s2, s3, i, j + 1);

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        if(n + m != s3.length()) return false;
        dp.assign(n + 1, vector<int>(m + 1, - 1));
        return solve(s1, s2, s3, 0, 0);
    }
};