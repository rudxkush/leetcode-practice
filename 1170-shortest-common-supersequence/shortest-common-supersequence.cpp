class Solution {
public:
    string shortestCommonSupersequenceHelper(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        string ans = "";
        while(i > 0 && j > 0) {
            if(s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--, j--;
            } else if(lcs[i - 1][j] > lcs[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }
        while(i > 0) {
            ans += s1[i - 1];
            i--;
        }
        while(j > 0) {
            ans += s2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        // abac
        // cab
        // lcs -> ab
        // cabac
        // abaccab -> 2 lcs here
        // we shall try to reomve 1 lcs from it in order to get the shortest
        // string that has both str1 and str2 as subsequence
        return shortestCommonSupersequenceHelper(str1, str2);
    }
};