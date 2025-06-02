class Solution {
public:
    bool compareTheTwo(string& longer, string& shorter) {
        if (longer.length() != shorter.length() + 1) return false;
        int i = 0, j = 0;
        int len = longer.length();
        while(i < len) {
            if(shorter[j] == longer[i] && j < shorter.length()) {
                i++, j++;
            } else {
                i++;
            }
        }
        return j == shorter.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compareTheTwo(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};