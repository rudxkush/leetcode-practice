class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string h = s;
        reverse(h.begin(), h.end());
        int n = s.length();

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

        return lcs[n][n];
    }
};

// vector<vector<int>> dp;
// int helper(string& s, int i, int j) {
//     // Base cases
//     if (i > j)
//         return 0;
//     if (i == j)
//         return 1;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s[i] == s[j]) {
//         dp[i][j] = 2 + helper(s, i + 1, j - 1);
//     } else {
//         dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
//     }

//     return dp[i][j];
// }

// int longestPalindromeSubseq(string s) {
//     int n = s.length();
//     dp = vector<vector<int>>(n, vector<int>(n, -1));
//     return helper(s, 0, n - 1);
// }

// class Solution {
// public:
//     bool isValid(string& ans) {
//         int l = 0, r = ans.length()-1;

//         while(l < r) {
//             if(ans[l] != ans[r]) {
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     int genAllSubseq(string& s, int i, string& ans) {
//         // base case
//         if(i == s.length()) {
//             if(isValid(ans)) {
//                 return ans.length();
//             }
//             return 0;
//         }
//         string includeStr = ans + s[i];
//         // inclusion
//         int include = genAllSubseq(s, i+1, includeStr);
//         // exclusion
//         int exclude = genAllSubseq(s, i+1, ans);
//         return max(include, exclude);
//     }
//     int longestPalindromeSubseq(string s) {
//         string ans = "";
//         return genAllSubseq(s, 0, ans);
//     }
// };
