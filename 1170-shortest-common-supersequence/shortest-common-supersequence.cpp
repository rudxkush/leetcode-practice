class Solution {
public:
    // A sequence where the order of elements is maintained,
    // but the elements do not need to be continuous.
    string shortestCommonSupersequenceHelper(int n, int m, string& s1, string& s2) {
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }
        int i = n, j = m;
        string str = "";
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                str += s1[i - 1];
                i--, j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                str += s1[i - 1];
                i--;
            } else {
                str += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            str += s1[i - 1];
            i--;
        }

        while (j > 0) {
            str += s2[j - 1];
            j--;
        }

        reverse(str.begin(), str.end());
        return str;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int l = str1.length();
        int m = str2.length();
        return shortestCommonSupersequenceHelper(l, m, str1, str2);
    }
};