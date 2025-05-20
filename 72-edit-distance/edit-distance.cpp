class Solution {
public:
    int minDistanceHelper(string& s1, string& s2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return minDistanceHelper(word1, word2, n, m);
    }
};
/*
   word1 = "intention"
   word2 = "execution"
       i n t e n t i o n
     0 1 2 3 4 5 6 7 8 9
   e 1 1 2 3 3 4 5 6 7 8
   x 2 2 2
   e 3
   c 4
   u 5
   t 6
   i 7
   o 8
   n 9

*/