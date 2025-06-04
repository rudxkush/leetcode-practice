class Solution {
public:
    int length = 0;
    vector<vector<vector<int>>> dp;
    pair<int, int> countBits(const string& s) {
        int ones = 0, zeroes = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
            else if (c == '0')
                zeroes++;
        }
        return {zeroes, ones};
    }

    int helper(vector<string>& strs, int m, int n, int i) {
        // base case
        if (i == strs.size()) {
            return 0;
        }

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        // choose to pick
        auto [countZeroes, countOnes] = countBits(strs[i]);
        int include = 0;
        if (m >= countZeroes && n >= countOnes)
            include = 1 + helper(strs, m - countZeroes, n - countOnes, i + 1);

        // choose not to pick
        int exclude = helper(strs, m, n, i + 1);

        return dp[i][m][n] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size(),
                  vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, m, n, 0);
    }
};

/*

     1  0
     0  0  0  1
     1  1  1  0  0  1
     1
     0
     No of 0's, m = 5
     No of 1's, n = 3
     output : 4
     Count all the subset that have atmost m 0's and n 1's

*/