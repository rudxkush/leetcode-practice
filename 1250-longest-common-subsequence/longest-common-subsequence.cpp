class Solution {
public:
    vector<vector<int>> dp;
    int n = 0, m = 0;
    int longestCommonSubsequenceHelper(string& text1, int i, string& text2, int j) {
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + longestCommonSubsequenceHelper(text1, i + 1, text2, j + 1);
        else  
            return dp[i][j] =  max(longestCommonSubsequenceHelper(text1, i + 1, text2, j),
                                   longestCommonSubsequenceHelper(text1, i, text2, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        dp.resize(n, vector<int>(m, -1));
        return longestCommonSubsequenceHelper(text1, 0, text2, 0);
    }
};