class Solution {
public:
    bool isOneApart(string& longer, string& shorter) {
        if (longer.length() != shorter.length() + 1) return false;
        int i = 0, j = 0;
        while (i < longer.length()) {
            if (j < shorter.length() && longer[i] == shorter[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return j == shorter.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        vector<int> dp(n, 1); 
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < i; ++prev) {
                if (isOneApart(words[i], words[prev]) && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
