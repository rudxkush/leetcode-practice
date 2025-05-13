class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j)
            return true;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int mcmHelper(string& s, int i, int j) {
        // base case
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minPartitionCnt = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            int left = 0, right = 0;
            if (isPalindrome(s, i, k)) {
                if (dp[k + 1][j] != -1)
                    right = dp[k + 1][j];
                else {
                    right = mcmHelper(s, k + 1, j);
                    dp[k + 1][j] = right;
                }
                minPartitionCnt = min(minPartitionCnt, 1 + right);
            }
        }
        return dp[i][j] = minPartitionCnt;
    }
    int minCut(string& s) {
        dp.resize(s.length(), vector<int>(s.length(), -1));
        return mcmHelper(s, 0, s.length() - 1);
    }
};